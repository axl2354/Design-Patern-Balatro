// GameManager.cpp
#include <iostream>
#include "GameManager.h"

void GameManager::runSession() {
    std::cout << "=== Run Started ===\n"; // [cite: 345]
    
    Hand hand = handGenerator.generateHand(); // 
    handPlayer.playHand(); // 
    int score = scoringRule.scoreHand(hand); // 
    bool win = blindRule.checkBlind(score); // 
    int reward = rewardRule.earnMoney(win, score); // 
    
    std::cout << "Money gained: " << reward << "\n"; // [cite: 347]
    std::cout << "=== Run Ended ===\n"; // [cite: 348]
}