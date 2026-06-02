#pragma once

#include <string>

enum class BlindType {
    SmallBlind,
    BigBlind,
    BossBlind
};

class BlindState {
public:
    virtual ~BlindState() = default;

    virtual std::string getName() const = 0;
    virtual BlindType getType() const = 0;
    virtual bool canSkip() const = 0;
    virtual int skipReward(int score) const = 0;
    virtual int requiredScore() const = 0;
    virtual int getAnte() const = 0;
};
