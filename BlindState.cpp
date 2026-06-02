#include "BlindState.h"
#include <iostream>

BlindState::BlindState(int anteValue): ante(anteValue) {}
BlindState::~BlindState() = default;

int BlindState::getAnte() const {
    return ante;
}

SmallBlindState::SmallBlindState(int anteValue): BlindState(anteValue) {}

std::string SmallBlindState::getName() const {
    return "Small Blind";
}

BlindType SmallBlindState::getType() const {
    return BlindType::SmallBlind;
}

bool SmallBlindState::canSkip() const {
    return true;
}

int SmallBlindState::skipReward(int score) const {
    return ante + 1;
}

int SmallBlindState::requiredScore() const {
    return 5 + ante;
}

BigBlindState::BigBlindState(int anteValue): BlindState(anteValue) {}

std::string BigBlindState::getName() const {
    return "Big Blind";
}

BlindType BigBlindState::getType() const {
    return BlindType::BigBlind;
}

bool BigBlindState::canSkip() const {
    return true;
}

int BigBlindState::skipReward(int score) const {
    return ante + 2;
}

int BigBlindState::requiredScore() const {
    return 5 + ante;
}

BossBlindState::BossBlindState(int anteValue): BlindState(anteValue) {}

std::string BossBlindState::getName() const {
    return "Boss Blind";
}

BlindType BossBlindState::getType() const {
    return BlindType::BossBlind;
}

bool BossBlindState::canSkip() const {
    return false;
}

int BossBlindState::skipReward(int score) const {
    return 0;
}

int BossBlindState::requiredScore() const {
    return 6 + ante;
}

BlindStateManager::BlindStateManager(): state(std::unique_ptr<BlindState>(new SmallBlindState(1))) {}

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
    return state->getAnte() >= 8;
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
    if (state->getAnte() >= 8) {
        std::cout << "Ante reached " << state->getAnte() << ". Blind progression completed.\n";
    }
}

void BlindStateManager::moveToNextState() {
    BlindType type = state->getType();
    int currentAnte = state->getAnte();

    if (type == BlindType::SmallBlind) {
        state.reset(new BigBlindState(currentAnte));
        std::cout << "Progressing to Big Blind...\n";
        return;
    }

    if (type == BlindType::BigBlind) {
        state.reset(new BossBlindState(currentAnte));
        std::cout << "Progressing to Boss Blind...\n";
        return;
    }

    if (type == BlindType::BossBlind) {
        int nextAnte = currentAnte + 1;
        state.reset(new SmallBlindState(nextAnte));
        std::cout << "Blind cycle complete. Ante increased to " << nextAnte << ".\n";
        return;
    }
}
