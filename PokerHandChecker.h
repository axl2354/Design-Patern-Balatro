
#include "Hand.h"
#include <map>
#include <algorithm>

class PokerHandChecker
{
public:
    virtual HandRank check(const Hand &hand);
    void setNext(PokerHandChecker *next);

private:
    PokerHandChecker *nextChecker = nullptr;
};