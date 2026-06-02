#pragma once

#include "BlindState.h"
#include <memory>

class BlindStateManager {
public:
    explicit BlindStateManager(int startingSmallAnte = 1);
    const BlindState& currentState() const;
    bool canSkip() const;
    int currentAnte() const;
    int currentRequiredScore() const;
    bool isWinCondition() const;
    int skipReward(int score) const;
    void printStatus() const;
    void advanceState();

private:
    std::unique_ptr<BlindState> state;
    int smallAnte;
    void moveToNextState();
};
