#ifndef THREEOFAKINDCHECKER_H
#define THREEOFAKINDCHECKER_H
#include "../PokerHandChecker.h"
using namespace std;
class ThreeOfAKindChecker:public PokerHandChecker{
public:
    HandRank check(const Hand& hand) override;
};
#endif