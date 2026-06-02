// GameManager.cpp
#include "GameManager.h"
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

        Hand hand = handGenerator.generateHand(deck);
        Hand playedHand = handPlayer.playHand(hand);
        int score = scoringRule.scoreHand(playedHand);

        if (blindStateManager.canSkip() && score < blindStateManager.currentRequiredScore()) {
            int reward = blindStateManager.skipReward(score);
            std::cout << "Skip chosen for " << blindStateManager.currentState().getName() << ". Reward: $" << reward << "\n";
            deck.returnHand(playedHand);
        } else {
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