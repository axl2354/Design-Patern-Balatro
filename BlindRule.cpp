// BlindRule.cpp
#include "BlindRule.h"
#include <iostream>

bool BlindRule::checkBlind(int score, int threshold) {
    std::cout << "Checking blind requirement against threshold " << threshold << "...\n";
    bool win = (score >= threshold);
    std::cout << "Result: " << (win ? "WIN" : "LOSE") << "\n";
    return win;
}