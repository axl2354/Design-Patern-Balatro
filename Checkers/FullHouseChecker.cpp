
#include <iostream>
#include "FullHouseChecker.h"
using namespace std;
HandRank FullHouseChecker::check(const Hand& hand) {
    int rankCounts[15] = {};
    for (const Card& card : hand.cards) {
        if (card.rank >= 2 && card.rank <= 14) {
            rankCounts[card.rank]++;
        }
    }

    int tripleRanks = 0;
    int pairRanks = 0;
    for (int rank = 2; rank <= 14; ++rank) {
        if (rankCounts[rank] >= 3) {
            tripleRanks++;
        }
        if (rankCounts[rank] >= 2) {
            pairRanks++;
        }
    }

    cout << "Checking for Full House...\n";
    bool hasFullHouse = (tripleRanks >= 2) || (tripleRanks >= 1 && pairRanks >= 2);
    if (hasFullHouse) {
        cout << "Got Full House...\n";
        return HandRank::FullHouse;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}