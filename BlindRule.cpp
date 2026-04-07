// BlindRule.cpp
#include <iostream>
#include "BlindRule.h"

bool BlindRule::checkBlind(int score) {
    std::cout << "Checking blind requirement...\n"; // [cite: 229]
    if (score >= 5) { // [cite: 231]
        std::cout << "Result: WIN\n"; // [cite: 232]
        return true;
    }
    std::cout << "Result: LOSE\n"; // [cite: 234]
    return false;
}