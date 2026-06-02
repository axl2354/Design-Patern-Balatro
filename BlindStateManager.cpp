#include "BlindStateManager.h"
#include "SmallBlind.h"
#include "BigBlind.h"
#include "BossBlind.h"
#include <iostream>

BlindStateManager::BlindStateManager(int startingSmallAnte)
    : smallAnte(startingSmallAnte) {
    state.reset(new SmallBlindState(smallAnte));
}

const BlindState& BlindStateManager::currentState() const {
    return *state;
}

bool BlindStateManager::canSkip() const {
    return state->canSkip();
}

int BlindStateManager::currentAnte() const {
    return state->getAnte();
}

int BlindStateManager::currentRequiredScore() const {
    return state->requiredScore();
}

bool BlindStateManager::isWinCondition() const {
    return smallAnte >= 8;
}

int BlindStateManager::skipReward(int score) const {
    return state->skipReward(score);
}

void BlindStateManager::printStatus() const {
    std::cout << "Blind state: " << state->getName()
              << " | Ante: " << state->getAnte()
              << " | Required score: " << state->requiredScore()
              << " | Skip available: " << (state->canSkip() ? "yes" : "no")
              << "\n";
}

void BlindStateManager::advanceState() {
    moveToNextState();
    if (smallAnte >= 8) {
        std::cout << "Small ante reached " << smallAnte << ". Blind progression completed.\n";
    }
}

void BlindStateManager::moveToNextState() {
    BlindType type = state->getType();

    if (type == BlindType::SmallBlind) {
        state.reset(new BigBlindState(smallAnte));
        std::cout << "Progressing to Big Blind...\n";
        return;
    }

    if (type == BlindType::BigBlind) {
        state.reset(new BossBlindState(smallAnte));
        std::cout << "Progressing to Boss Blind...\n";
        return;
    }

    if (type == BlindType::BossBlind) {
        smallAnte += 1;
        state.reset(new SmallBlindState(smallAnte));
        std::cout << "Blind cycle complete. Small ante increased to " << smallAnte << ".\n";
        return;
    }
}
