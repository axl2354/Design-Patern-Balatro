#include <iostream>
#include "FlushFiveChecker.h"
using namespace std;
HandRank FlushFiveChecker::check(const Hand& hand) {
    cout << "Checking for Flush Five...\n";
    if (hand.value == 13) {
        cout << "Got Flush Five...\n";
        return HandRank::FlushFive;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}