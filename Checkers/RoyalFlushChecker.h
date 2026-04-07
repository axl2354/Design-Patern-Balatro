#ifndef ROYALFLUSHCHECKER_H
#define ROYALFLUSHCHECKER_H
#include "../PokerHandChecker.h"
using namespace std;
class RoyalFlushChecker:public PokerHandChecker{
public:
    HandRank check(const Hand& hand) override;
};
#endif