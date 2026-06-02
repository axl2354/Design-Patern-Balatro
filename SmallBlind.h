#pragma once

#include "BlindState.h"

class SmallBlindState : public BlindState {
public:
    explicit SmallBlindState(int smallAnte);
    std::string getName() const override;
    BlindType getType() const override;
    bool canSkip() const override;
    int skipReward(int score) const override;
    int requiredScore() const override;
    int getAnte() const override;

private:
    int ante;
};
