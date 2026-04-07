
#include <iostream>
#include "HighCardChecker.h"
using namespace std;
HandRank HighCardChecker::check(const Hand& hand) {
    cout << "Checking for High Card...\n";
    if (hand.value == 1) {
        cout << "Got High Card...\n";
        return HandRank::HighCard;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}