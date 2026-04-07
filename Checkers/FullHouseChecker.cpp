
#include <iostream>
#include "FullHouseChecker.h"
using namespace std;
HandRank FullHouseChecker::check(const Hand& hand) {
    cout << "Checking for Full House...\n";
    if (hand.value == 7) {
        cout << "Got Full House...\n";
        return HandRank::FullHouse;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}