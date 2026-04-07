
#include <iostream>
#include "StraightFlushChecker.h"
using namespace std;
HandRank StraightFlushChecker::check(const Hand& hand) {
    cout << "Checking for Straight Flush...\n";
    if (hand.value == 9) {
        cout << "Got Straight Flush...\n";
        return HandRank::StraightFlush;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}