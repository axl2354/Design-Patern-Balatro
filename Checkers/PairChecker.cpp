
#include <iostream>
#include "PairChecker.h"
using namespace std;
HandRank PairChecker::check(const Hand& hand) {
    int rankCounts[15] = {};
    for (const Card& card : hand.cards) {
        if (card.rank >= 2 && card.rank <= 14) {
            rankCounts[card.rank]++;
        }
    }

    cout << "Checking for Pair...\n";
    for (int rank = 2; rank <= 14; ++rank) {
        if (rankCounts[rank] >= 2) {
            cout << "Got Pair...\n";
            return HandRank::Pair;
        }
    }

    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}