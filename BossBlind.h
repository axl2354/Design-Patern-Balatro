#pragma once

#include "BlindState.h"

class BossBlindState : public BlindState {
public:
    // Accept the small blind ante as the anchor and compute boss ante from it
    explicit BossBlindState(int smallAnte);
    std::string getName() const override;
    BlindType getType() const override;
    bool canSkip() const override;
    int skipReward(int score) const override;
    int requiredScore() const override;
    int getAnte() const override;

private:
    int ante;
    int required_score;
};
