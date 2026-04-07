#include <iostream>
#include "FlushChecker.h"
using namespace std;
HandRank FlushChecker::check(const Hand& hand) {
    cout << "Checking for Flush...\n";
    if (hand.value == 6) {
        cout << "Got Flush...\n";
        return HandRank::Flush;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}