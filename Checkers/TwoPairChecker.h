#ifndef TWOPAIRCHECKER_H
#define TWOPAIRCHECKER_H
#include "../PokerHandChecker.h"
using namespace std;
class TwoPairChecker:public PokerHandChecker{
public:
    HandRank check(const Hand& hand) override;
};
#endif