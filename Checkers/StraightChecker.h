#ifndef STRAIGHTCHECKER_H
#define STRAIGHTCHECKER_H
#include "../PokerHandChecker.h"
using namespace std;
class StraightChecker:public PokerHandChecker{
public:
    HandRank check(const Hand& hand) override;
};
#endif