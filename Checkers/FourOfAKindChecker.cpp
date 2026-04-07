
#include <iostream>
#include "FourOfAKindChecker.h"
using namespace std;
HandRank FourOfAKindChecker::check(const Hand& hand) {
    cout << "Checking for Four of a Kind...\n";
    if (hand.value == 8) {
        cout << "Got Four of a Kind...\n";
        return HandRank::FourOfAKind;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}