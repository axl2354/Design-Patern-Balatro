
#include <iostream>
#include "PairChecker.h"
using namespace std;
HandRank PairChecker::check(const Hand& hand) {
    cout << "Checking for Pair...\n";
    if (hand.value == 2) {
        cout << "Got Pair...\n";
        return HandRank::Pair;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}