#pragma once

#include <memory>
#include <string>

enum class BlindType {
    SmallBlind,
    BigBlind,
    BossBlind
};

class BlindState {
public:
    explicit BlindState(int anteValue);
    virtual ~BlindState();

    virtual std::string getName() const = 0;
    virtual BlindType getType() const = 0;
    virtual bool canSkip() const = 0;
    virtual int skipReward(int score) const = 0;
    virtual int requiredScore() const = 0;

    int getAnte() const;

protected:
    int ante;
};

class SmallBlindState : public BlindState {
public:
    explicit SmallBlindState(int anteValue);
    std::string getName() const override;
    BlindType getType() const override;
    bool canSkip() const override;
    int skipReward(int score) const override;
    int requiredScore() const override;
};

class BigBlindState : public BlindState {
public:
    explicit BigBlindState(int anteValue);
    std::string getName() const override;
    BlindType getType() const override;
    bool canSkip() const override;
    int skipReward(int score) const override;
    int requiredScore() const override;
};

class BossBlindState : public BlindState {
public:
    explicit BossBlindState(int anteValue);
    std::string getName() const override;
    BlindType getType() const override;
    bool canSkip() const override;
    int skipReward(int score) const override;
    int requiredScore() const override;
};

class BlindStateManager {
public:
    BlindStateManager();
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
    void moveToNextState();
};
