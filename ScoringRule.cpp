// ScoringRule.cpp
#include "ScoringRule.h"
#include <iostream>

ScoringRule::ScoringRule() {
    // Allocate all checkers
    flushFive = new FlushFiveChecker();
    flushHouse = new FlushHouseChecker();
    fiveOfAKind = new FiveOfAKindChecker();
    royalFlush = new RoyalFlushChecker();
    straightFlush = new StraightFlushChecker();
    fourOfAKind = new FourOfAKindChecker();
    fullHouse = new FullHouseChecker();
    flush = new FlushChecker();
    straight = new StraightChecker();
    threeOfAKind = new ThreeOfAKindChecker();
    twoPair = new TwoPairChecker();
    pairChecker = new PairChecker();
    highCard = new HighCardChecker();

    // Chain them from strongest to weakest
    flushFive->setNext(flushHouse);
    flushHouse->setNext(fiveOfAKind);
    fiveOfAKind->setNext(royalFlush);
    royalFlush->setNext(straightFlush);
    straightFlush->setNext(fourOfAKind);
    fourOfAKind->setNext(fullHouse);
    fullHouse->setNext(flush);
    flush->setNext(straight);
    straight->setNext(threeOfAKind);
    threeOfAKind->setNext(twoPair);
    twoPair->setNext(pairChecker);
    pairChecker->setNext(highCard);

    // Set the starting point
    rootChecker = flushFive;
}

ScoringRule::~ScoringRule() {
    // Clean up allocated memory
    delete flushFive;
    delete flushHouse;
    delete fiveOfAKind;
    delete royalFlush;
    delete straightFlush;
    delete fourOfAKind;
    delete fullHouse;
    delete flush;
    delete straight;
    delete threeOfAKind;
    delete twoPair;
    delete pairChecker;
    delete highCard;
}

int ScoringRule::scoreHand(const Hand& hand) {
    std::cout << "Calculating hand score...\n";
    HandRank rank = rootChecker->check(hand);
    return convertRankToScore(rank);
}

int ScoringRule::convertRankToScore(HandRank rank) {
    // Convert hand rank to score value
    switch (rank) {
        case HandRank::FlushFive: return 200;
        case HandRank::FlushHouse: return 150;
        case HandRank::FiveOfAKind: return 120;
        case HandRank::RoyalFlush: return 100;
        case HandRank::StraightFlush: return 75;
        case HandRank::FourOfAKind: return 60;
        case HandRank::FullHouse: return 55;
        case HandRank::Flush: return 45;
        case HandRank::Straight: return 30;
        case HandRank::ThreeOfAKind: return 25;
        case HandRank::TwoPair: return 20;
        case HandRank::Pair: return 10;
        case HandRank::HighCard: default: return 5;
    }
}

