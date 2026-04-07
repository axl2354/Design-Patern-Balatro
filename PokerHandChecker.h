#ifndef POKERHANDCHECKER_H
#define POKERHANDCHECKER_H
#include "Hand.h"
#include <map>
#include <algorithm>

enum HandRank {
    HighCard,
    Pair,
    TwoPair,
    ThreeOfAKind,
    Straight,
    Flush,
    FullHouse,
    FourOfAKind,
    StraightFlush,
    RoyalFlush,
    FiveOfAKind,
    FlushHouse,
    FlushFive
};

class PokerHandChecker
{
public:
    virtual HandRank check(const Hand &hand);
    void setNext(PokerHandChecker* next);

protected:
    PokerHandChecker* nextChecker = nullptr;
};
#endif