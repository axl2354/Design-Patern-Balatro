
#include <iostream>
#include "StraightChecker.h"
using namespace std;
HandRank StraightChecker::check(const Hand& hand) {
    cout << "Checking for Straight...\n";
    if (hand.value == 5) {
        cout << "Got Straight...\n";
        return HandRank::Straight;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}