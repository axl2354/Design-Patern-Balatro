#pragma once

#include "BlindState.h"

class BigBlindState : public BlindState {
public:
    // Accept the small blind ante as the anchor and compute big ante from it
    explicit BigBlindState(int smallAnte);
    std::string getName() const override;
    BlindType getType() const override;
    bool canSkip() const override;
    int skipReward(int score) const override;
    int requiredScore() const override;
    int getAnte() const override;

private:
    int ante;
};
