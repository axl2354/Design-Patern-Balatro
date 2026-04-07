// ScoringRule.h
#pragma once
#include "Hand.h"
#include "PokerHandChecker.h"
#include "Checkers.h"

class ScoringRule {
public:
    ScoringRule();
    int scoreHand(const Hand& hand);
    int convertRankToScore(HandRank rank);

private:
    // Instansiasi semua 13 checker
    FlushFiveChecker flushFive;
    FlushHouseChecker flushHouse;
    FiveOfAKindChecker fiveOfAKind;
    RoyalFlushChecker royalFlush;
    StraightFlushChecker straightFlush;
    FourOfAKindChecker fourOfAKind;
    FullHouseChecker fullHouse;
    FlushChecker flush;
    StraightChecker straight;
    ThreeOfAKindChecker threeOfAKind;
    TwoPairChecker twoPair;
    PairChecker pairChecker;
    HighCardChecker highCard;
    
    PokerHandChecker* rootChecker = nullptr;
};