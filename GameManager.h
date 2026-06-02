// GameManager.h
#pragma once
#include "HandGenerator.h"
#include "HandPlayer.h"
#include "ScoringRule.h"
#include "BlindRule.h"
#include "BlindState.h"
#include "RewardRule.h"

class GameManager {
public:
    GameManager();
    ~GameManager();
    void runSession();
private:
    Deck deck;
    HandGenerator handGenerator;
    HandPlayer handPlayer;
    ScoringRule scoringRule;
    BlindRule blindRule;
    BlindStateManager blindStateManager;
    RewardRule rewardRule;
};