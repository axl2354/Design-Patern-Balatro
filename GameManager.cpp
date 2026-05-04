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
    
    Hand hand = handGenerator.generateHand();
    Hand playedHand = handPlayer.playHand(hand);
    int score = scoringRule.scoreHand(playedHand);
    bool win = blindRule.checkBlind(score);
    int reward = rewardRule.earnMoney(win, score);
    
    std::cout << "Money gained: $" << reward << "\n";
    std::cout << "=== Run Ended ===\n";
}