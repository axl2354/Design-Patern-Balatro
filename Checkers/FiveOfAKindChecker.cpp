#include <iostream>
#include "FiveOfAKindChecker.h"
using namespace std;
HandRank FiveOfAKindChecker::check(const Hand& hand) {
    cout << "Checking for Five of a Kind...\n";
    if (hand.value == 11) {
        cout << "Got Five of a Kind...\n";
        return HandRank::FiveOfAKind;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}