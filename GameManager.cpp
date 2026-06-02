// GameManager.cpp
#include "GameManager.h"
#include "SkipRewards/BonusHandCommand.h"
#include "SkipRewards/FreePlayingCard.h"
#include <cctype>
#include <iostream>
#include <random>

GameManager::GameManager() {
}

GameManager::~GameManager() {
    // ScoringRule destructor will be called automatically
}

std::unique_ptr<SkipCommand> GameManager::createRandomSkipReward() {
    static std::mt19937 gen(static_cast<unsigned int>(std::random_device{}()));
    std::uniform_int_distribution<> rewardDist(0, 1);

    if (rewardDist(gen) == 0) {
        return std::make_unique<BonusHandCommand>(skipRewardReceiver, deck, 2);
    }
    return std::make_unique<FreePlayingCard>(skipRewardReceiver, deck);
}

void GameManager::runSession() {
    std::cout << "=== Run Started ===\n";

    while (!blindStateManager.isWinCondition()) {
        blindStateManager.printStatus();

        if (blindStateManager.canSkip()) {
            skipRewardInvoker.clearCommands();
            skipRewardInvoker.addCommand(createRandomSkipReward());
            std::cout << "A random skip reward has been prepared.\n";
        }

        bool skipBlind = false;
        if (blindStateManager.canSkip()) {
            char choice;
            do {
                std::cout << "Skip " << blindStateManager.currentState().getName() << "? (y/n): ";
                std::cin >> choice;
                choice = static_cast<char>(std::tolower(static_cast<unsigned char>(choice)));
            } while (choice != 'y' && choice != 'n');

            skipBlind = (choice == 'y');
        }

        if (skipBlind) {
            skipRewardInvoker.executeByEvent(EventType::BlindEnter);
            int reward = blindStateManager.skipReward(0);
            std::cout << "Skip chosen for " << blindStateManager.currentState().getName()
                      << ". Reward: $" << reward << "\n";
            blindStateManager.advanceState();
            skipRewardInvoker.executeByEvent(EventType::BlindClear);
        } else {
            skipRewardInvoker.clearCommands();
            Hand hand = handGenerator.generateHand(deck);
            Hand playedHand = handPlayer.playHand(hand);
            int score = scoringRule.scoreHand(playedHand);

            bool win = blindRule.checkBlind(score, blindStateManager.currentRequiredScore());
            int reward = rewardRule.earnMoney(win, score);
            std::cout << "Hand score: " << score << ". ";
            std::cout << (win ? "Blind cleared." : "Blind failed.") << "\n";
            std::cout << "Money gained: $" << reward << "\n";
            deck.returnHand(playedHand);
            blindStateManager.advanceState();
        }

        if (blindStateManager.isWinCondition()) {
            std::cout << "\nAnte has reached " << blindStateManager.currentAnte() << ". You win the blind progression!\n";
            break;
        }
    }

    std::cout << "=== Run Ended ===\n";
}