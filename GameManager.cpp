// GameManager.cpp
#include "GameManager.h"
#include "SkipRewards/BonusHandCommand.h"
#include "SkipRewards/FreePlayingCard.h"
#include <cctype>
#include <iostream>
#include <random>

GameManager::GameManager()
    : handCount(3) {
}

GameManager::~GameManager() {
    // ScoringRule destructor will be called automatically
}

std::unique_ptr<SkipCommand> GameManager::createRandomSkipReward() {
    static std::mt19937 gen(static_cast<unsigned int>(std::random_device{}()));
    std::uniform_int_distribution<> rewardDist(0, 1);

    if (rewardDist(gen) == 0) {
        return std::make_unique<BonusHandCommand>(skipRewardReceiver, handCount, 1);
    }
    return std::make_unique<FreePlayingCard>(skipRewardReceiver, deck);
}

void GameManager::runSession() {
    std::cout << "=== Run Started ===\n";
    BlindType currentBlindType = blindStateManager.currentState().getType();
    bool askedSkipThisBlind = false;

    while (!blindStateManager.isWinCondition()) {
        blindStateManager.printStatus();
        std::cout << "Remaining hand plays this blind: " << handCount.getRemaining() << "\n";

        if (blindStateManager.currentState().getType() != currentBlindType) {
            currentBlindType = blindStateManager.currentState().getType();
            askedSkipThisBlind = false;
        }

        if (blindStateManager.canSkip()) {
            skipRewardInvoker.clearCommands();
            skipRewardInvoker.addCommand(createRandomSkipReward());
            std::cout << "A random skip reward has been prepared.\n";
        }

        bool skipBlind = false;
        if (handCount.isExhausted()) {
            std::cout << "No hand plays remaining this blind.\n";
            if (blindStateManager.canSkip()) {
                std::cout << "Skip is required because you have no plays left.\n";
                skipBlind = true;
            } else {
                std::cout << "You have no hand plays left and skip is unavailable. You lose.\n";
                break;
            }
        }

        if (!skipBlind && blindStateManager.canSkip() && !askedSkipThisBlind) {
            char choice;
            do {
                std::cout << "Skip " << blindStateManager.currentState().getName() << "? (y/n): ";
                std::cin >> choice;
                choice = static_cast<char>(std::tolower(static_cast<unsigned char>(choice)));
            } while (choice != 'y' && choice != 'n');

            skipBlind = (choice == 'y');
            askedSkipThisBlind = true;
        }

        if (skipBlind) {
            skipRewardInvoker.executeByEvent(EventType::Instant);
            int reward = blindStateManager.skipReward(0);
            std::cout << "Skip chosen for " << blindStateManager.currentState().getName()
                      << ".\n";
            blindStateManager.advanceState();
            handCount.reset();
        } else {
            skipRewardInvoker.executeByEvent(EventType::BlindEnter);
            skipRewardInvoker.clearCommands();
            Hand hand = handGenerator.generateHand(deck);
            Hand playedHand = handPlayer.playHand(hand);
            int score = score + scoringRule.scoreHand(playedHand);

            bool win = blindRule.checkBlind(score, blindStateManager.currentRequiredScore());
            int reward = rewardRule.earnMoney(win, score);
            std::cout << "Hand score: " << score << ". ";
            std::cout << (win ? "Blind cleared." : "Blind failed.") << "\n";
            std::cout << "Money gained: $" << reward << "\n";
            deck.returnHand(playedHand);
            handCount.consumePlay();
            std::cout << "Remaining hand plays after this hand: " << handCount.getRemaining() << "\n";

            if (win) {
                blindStateManager.advanceState();
                score = 0;
                handCount.reset();
                skipRewardInvoker.executeByEvent(EventType::BlindClear);
            } else if (handCount.isExhausted()) {
                std::cout << "No hand plays left for this blind and you failed to clear it. You lose.\n";
                break;
            } else {
                std::cout << "You still have hand plays remaining. Staying in the current blind.\n";
            }
        }

        if (blindStateManager.isWinCondition()) {
            std::cout << "\nAnte has reached " << blindStateManager.currentAnte() << ". You win the blind progression!\n";
            break;
        }
    }

    std::cout << "=== Run Ended ===\n";
}
