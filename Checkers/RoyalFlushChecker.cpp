
#include <iostream>
#include "RoyalFlushChecker.h"
using namespace std;
HandRank RoyalFlushChecker::check(const Hand& hand) {
    cout << "Checking for Royal Flush...\n";
    if (hand.value == 10) {
        cout << "Got Royal Flush...\n";
        return HandRank::RoyalFlush;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}