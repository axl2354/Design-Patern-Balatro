
#include <iostream>
#include "FlushHouseChecker.h"
using namespace std;
HandRank FlushHouseChecker::check(const Hand& hand) {
    cout << "Checking for Flush House...\n";
    int rankCounts[15] = {};
    int heartsCount = 0;
    int diamondsCount = 0;
    int clubsCount = 0;
    int spadesCount = 0;

    for (const Card& card : hand.cards) {
        if (card.suit == 'H') heartsCount++;
        else if (card.suit == 'D') diamondsCount++;
        else if (card.suit == 'C') clubsCount++;
        else if (card.suit == 'S') spadesCount++;

        if (card.rank >= 2 && card.rank <= 14) {
            rankCounts[card.rank]++;
        }
    }

    bool hasFlush = (heartsCount >= 5 || diamondsCount >= 5 || clubsCount >= 5 || spadesCount >= 5);
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

    bool hasFullHouse = (tripleRanks >= 1 && pairRanks >= 2);
    if (hasFlush && hasFullHouse) {
        cout << "Got Flush House...\n";
        return HandRank::FlushHouse;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
