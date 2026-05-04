#include <iostream>
#include "FlushFiveChecker.h"
using namespace std;
HandRank FlushFiveChecker::check(const Hand& hand) {
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

    cout << "Checking for Flush Five...\n";
    bool hasFlush = (heartsCount >= 5 || diamondsCount >= 5 || clubsCount >= 5 || spadesCount >= 5);
    bool hasFiveOfSameRank = false;
    for (int rank = 2; rank <= 14; ++rank) {
        if (rankCounts[rank] >= 5) {
            hasFiveOfSameRank = true;
            break;
        }
    }

    if (hasFlush && hasFiveOfSameRank) {
        cout << "Got Flush Five...\n";
        return HandRank::FlushFive;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}