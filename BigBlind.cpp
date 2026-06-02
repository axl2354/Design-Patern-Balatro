#include "BigBlind.h"
#include <cmath>

// big blind is 1.5x small blind; round to nearest integer
BigBlindState::BigBlindState(int smallAnte) {
    ante = static_cast<int>(std::lround(smallAnte * 1.5));
    required_score = 6 + ante;
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
