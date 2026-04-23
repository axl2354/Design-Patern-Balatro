
#include <iostream>
#include "FlushHouseChecker.h"
using namespace std;
HandRank FlushHouseChecker::check(const Hand& hand) {
    cout << "Checking for Flush House...\n";
    if (hand.value == 12) {
        cout << "Got Flush House...\n";
        return HandRank::FlushHouse;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}