#ifndef STRAIGHTFLUSHCHECKER_H
#define STRAIGHTFLUSHCHECKER_H
#include "../PokerHandChecker.h"
using namespace std;
class StraightFlushChecker:public PokerHandChecker{
public:
    HandRank check(const Hand& hand) override;
};
#endif