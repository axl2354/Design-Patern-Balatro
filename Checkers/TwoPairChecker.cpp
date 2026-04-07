
#include <iostream>
#include "TwoPairChecker.h"
using namespace std;
HandRank TwoPairChecker::check(const Hand& hand) {
    cout << "Checking for Two Pair...\n";
    if (hand.value == 3) {
        cout << "Got Two Pair...\n";
        return HandRank::TwoPair;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}