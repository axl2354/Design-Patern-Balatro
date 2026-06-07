// GameManager.h
#pragma once
#include <memory>
#include "Deck.h"
#include "HandGenerator.h"
#include "HandPlayer.h"
#include "ScoringRule.h"
#include "BlindRule.h"
#include "BlindStateManager.h"
#include "RewardRule.h"
#include "SkipRewards/SkipRewardInvoker.h"
#include "SkipRewards/SkipRewardReceiver.h"
#include "HandCount.h"

class GameManager {
public:
    GameManager();
    ~GameManager();
    void runSession();
private:
    std::unique_ptr<SkipCommand> createRandomSkipReward();

    Deck deck;
    HandGenerator handGenerator;
    HandPlayer handPlayer;
    ScoringRule scoringRule;
    BlindRule blindRule;
    BlindStateManager blindStateManager;
    RewardRule rewardRule;
    SkipRewardInvoker skipRewardInvoker;
    SkipRewardReceiver skipRewardReceiver;
    HandCount handCount;
};