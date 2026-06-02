#include "BossBlind.h"
#include <cmath>

BossBlindState::BossBlindState(int smallAnte) {
    ante = smallAnte;
    const int smallRequired = 5 + smallAnte;
    const int bigRequired = static_cast<int>(std::lround(smallRequired * 2));
    required_score = bigRequired;
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
    return required_score;
}

int BossBlindState::getAnte() const {
    return ante;
}
