#include "BigBlind.h"
#include <cmath>

BigBlindState::BigBlindState(int smallAnte) {
    ante = smallAnte;
    const int smallRequired = 5 + smallAnte;
    required_score = static_cast<int>(std::lround(smallRequired * 1.5));
}

std::string BigBlindState::getName() const {
    return "Big Blind";
}

BlindType BigBlindState::getType() const {
    return BlindType::BigBlind;
}

bool BigBlindState::canSkip() const {
    return true;
}

int BigBlindState::skipReward(int /*score*/) const {
    return ante + 2;
}

int BigBlindState::requiredScore() const {
    return required_score;
}

int BigBlindState::getAnte() const {
    return ante;
}
