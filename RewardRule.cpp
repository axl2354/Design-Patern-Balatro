// RewardRule.cpp
#include <iostream>
#include "RewardRule.h"

int RewardRule::earnMoney(bool win, int score) {
    std::cout << "Calculating reward...\n"; // [cite: 246]
    if (win) {
        return score; // [cite: 249]
    }
    return 0; // [cite: 250]
}