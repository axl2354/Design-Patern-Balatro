
#include <iostream>
#include "ThreeOfAKindChecker.h"
using namespace std;
HandRank ThreeOfAKindChecker::check(const Hand& hand) {
    int rankCounts[15] = {};
    for (const Card& card : hand.cards) {
        if (card.rank >= 2 && card.rank <= 14) {
            rankCounts[card.rank]++;
        }
    }

    cout << "Checking for Three of a Kind...\n";
    for (int rank = 2; rank <= 14; ++rank) {
        if (rankCounts[rank] >= 3) {
            cout << "Got Three of a Kind...\n";
            return HandRank::ThreeOfAKind;
        }
    }

    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}