// BlindRule.cpp
#include "BlindRule.h"
#include <iostream>

bool BlindRule::checkBlind(int score) {
    std::cout << "Checking blind requirement...\n";
    bool win = (score >= 5);
    std::cout << "Result: " << (win ? "WIN" : "LOSE") << "\n";
    return win;
}