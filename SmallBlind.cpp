#include "SmallBlind.h"
#include <string>

SmallBlindState::SmallBlindState(int smallAnte)
    : ante(smallAnte), required_score(5 + smallAnte) {}

std::string SmallBlindState::getName() const {
    return "Small Blind";
}

BlindType SmallBlindState::getType() const {
    return BlindType::SmallBlind;
}

bool SmallBlindState::canSkip() const {
    return true;
}

int SmallBlindState::skipReward(int /*score*/) const {
    return ante + 1;
}

int SmallBlindState::requiredScore() const {
    return required_score;
}

int SmallBlindState::getAnte() const {
    return ante;
}
