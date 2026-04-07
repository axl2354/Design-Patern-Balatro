#include "FlushChecker.h"
#include "StraightChecker.h"
#include "Hand.h"
#include <map>
#include <algorithm>
using namespace std;

virtual HandRank check(const Hand& hand) = 0;
void setNext(PokerHandChecker* next);
PokerHandChecker* nextChecker = nullptr;