#ifndef FIVEOFAKINDCHECKER_H
#define FIVEOFAKINDCHECKER_H
#include "../PokerHandChecker.h"
using namespace std;
class FiveOfAKindChecker:public PokerHandChecker{
public:
    HandRank check(const Hand& hand) override;
};
#endif