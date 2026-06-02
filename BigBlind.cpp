#include "BigBlind.h"
#include <cmath>

// big blind is 1.5x small blind; round to nearest integer
BigBlindState::BigBlindState(int smallAnte) {
    ante = static_cast<int>(std::lround(smallAnte * 1.5));
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
    return 6 + ante;
}

int BigBlindState::getAnte() const {
    return ante;
}
