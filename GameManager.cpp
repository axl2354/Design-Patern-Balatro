// GameManager.cpp
#include "GameManager.h"
#include <cctype>
#include <iostream>

GameManager::GameManager() {
}

GameManager::~GameManager() {
    // ScoringRule destructor will be called automatically
}

void GameManager::runSession() {
    std::cout << "=== Run Started ===\n";

    while (!blindStateManager.isWinCondition()) {
        blindStateManager.printStatus();

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
            int reward = blindStateManager.skipReward(0);
            std::cout << "Skip chosen for " << blindStateManager.currentState().getName()
                      << ". Reward: $" << reward << "\n";
        } else {
            Hand hand = handGenerator.generateHand(deck);
            Hand playedHand = handPlayer.playHand(hand);
            int score = scoringRule.scoreHand(playedHand);

            bool win = blindRule.checkBlind(score, blindStateManager.currentRequiredScore());
            int reward = rewardRule.earnMoney(win, score);
            std::cout << "Hand score: " << score << ". ";
            std::cout << (win ? "Blind cleared." : "Blind failed.") << "\n";
            std::cout << "Money gained: $" << reward << "\n";
            deck.returnHand(playedHand);
        }

        blindStateManager.advanceState();

        if (blindStateManager.isWinCondition()) {
            std::cout << "\nAnte has reached " << blindStateManager.currentAnte() << ". You win the blind progression!\n";
            break;
        }
    }

    std::cout << "=== Run Ended ===\n";
}