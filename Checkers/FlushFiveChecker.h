#ifndef FLUSHFIVECHECKER_H
#define FLUSHFIVECHECKER_H
#include "../PokerHandChecker.h"
using namespace std;
class FlushFiveChecker:public PokerHandChecker{
public:
    HandRank check(const Hand& hand) override;
};
#endif