// RewardRule.cpp
#include "RewardRule.h"
#include <iostream>

int RewardRule::earnMoney(bool win, int score) {
    std::cout << "Calculating reward...\n";
    return win ? score : 0;
}