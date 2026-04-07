#include <iostream>
#include "PokerHandChecker.h"
using namespace std;

HandRank PokerHandChecker::check(const Hand& hand) {
    cout << "Checking for High Card...\n";
    return HandRank::HighCard;
}
void PokerHandChecker::setNext(PokerHandChecker* next) {
    this->nextChecker = next;
}
