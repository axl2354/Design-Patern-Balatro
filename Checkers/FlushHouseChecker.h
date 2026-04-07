#ifndef FlUSHHOUSECHECKER_H
#define FlUSHHOUSECHECKER_H
#include "../PokerHandChecker.h"
using namespace std;
class FlushHouseChecker:public PokerHandChecker{
public:
    HandRank check(const Hand& hand) override;
};
#endif