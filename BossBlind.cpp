#include "BossBlind.h"
#include "BigBlind.h"
#include <cmath>

// boss blind is 2x big blind; since big blind = 1.5x small, boss = 3x small
BossBlindState::BossBlindState(int smallAnte) {
    int bigAnte = static_cast<int>(std::lround(smallAnte * 1.5));
    ante = bigAnte * 2;
}

std::string BossBlindState::getName() const {
    return "Boss Blind";
}

BlindType BossBlindState::getType() const {
    return BlindType::BossBlind;
}

bool BossBlindState::canSkip() const {
    return false;
}

int BossBlindState::skipReward(int /*score*/) const {
    return 0;
}

int BossBlindState::requiredScore() const {
    return 8 + ante;
}

int BossBlindState::getAnte() const {
    return ante;
}
