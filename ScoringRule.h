// ScoringRule.h
#pragma once
#include "Hand.h"
#include "PokerHandChecker.h"
#include "Checkers/FlushFiveChecker.h"
#include "Checkers/FlushHouseChecker.h"
#include "Checkers/FIveOfAKindChecker.h"
#include "Checkers/RoyalFlushChecker.h"
#include "Checkers/StraightFlushChecker.h"
#include "Checkers/FourOfAKindChecker.h"
#include "Checkers/FullHouseChecker.h"
#include "Checkers/FlushChecker.h"
#include "Checkers/StraightChecker.h"
#include "Checkers/ThreeOfAKindChecker.h"
#include "Checkers/TwoPairChecker.h"
#include "Checkers/PairChecker.h"
#include "Checkers/HighCardChecker.h"

class ScoringRule {
public:
    ScoringRule();
    ~ScoringRule();
    int scoreHand(const Hand& hand);
    int convertRankToScore(HandRank rank);

private:
    // Pointers to all checkers
    FlushFiveChecker* flushFive;
    FlushHouseChecker* flushHouse;
    FiveOfAKindChecker* fiveOfAKind;
    RoyalFlushChecker* royalFlush;
    StraightFlushChecker* straightFlush;
    FourOfAKindChecker* fourOfAKind;
    FullHouseChecker* fullHouse;
    FlushChecker* flush;
    StraightChecker* straight;
    ThreeOfAKindChecker* threeOfAKind;
    TwoPairChecker* twoPair;
    PairChecker* pairChecker;
    HighCardChecker* highCard;
    
    PokerHandChecker* rootChecker = nullptr;
};