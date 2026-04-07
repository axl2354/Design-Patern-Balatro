
#include <iostream>
#include "ThreeOfAKindChecker.h"
using namespace std;
HandRank ThreeOfAKindChecker::check(const Hand& hand) {
    cout << "Checking for Three of a Kind...\n";
    if (hand.value == 4) {
        cout << "Got Three of a Kind...\n";
        return HandRank::ThreeOfAKind;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}