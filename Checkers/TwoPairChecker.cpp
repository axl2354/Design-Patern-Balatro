
#include <iostream>
#include "TwoPairChecker.h"
using namespace std;


HandRank TwoPairChecker::check(const Hand& hand) {
    int rankCounts[15] = {};
    for (const Card& card : hand.cards) {
        if (card.rank >= 2 && card.rank <= 14) {
            rankCounts[card.rank]++;
        }
    }

    int pairRanks = 0;
    for (int rank = 2; rank <= 14; ++rank) {
        if (rankCounts[rank] >= 2) {
            pairRanks++;
        }
    }

    cout << "Checking for Two Pair...\n";
    if (pairRanks >= 2) {
        cout << "Got Two Pair...\n";
        return HandRank::TwoPair;
    }

    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}