#ifndef FLUSHCHECKER_H
#define FLUSHCHECKER_H
#include "../PokerHandChecker.h"
using namespace std;
class FlushChecker:public PokerHandChecker{
public:
    HandRank check(const Hand& hand) override;
};
#endif