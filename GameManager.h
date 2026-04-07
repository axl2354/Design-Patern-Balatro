// GameManager.h
#pragma once
#include "HandGenerator.h"
#include "HandPlayer.h"
#include "ScoringRule.h"
#include "BlindRule.h"
#include "RewardRule.h"

class GameManager {
public:
    void runSession(); // [cite: 352]
private:
    HandGenerator handGenerator; // [cite: 353]
    HandPlayer handPlayer; // [cite: 354]
    ScoringRule scoringRule; // [cite: 355]
    BlindRule blindRule; // [cite: 355]
    RewardRule rewardRule; // [cite: 356]
};