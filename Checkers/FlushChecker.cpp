#include <iostream>
#include "FlushChecker.h"
using namespace std;

HandRank FlushChecker::check(const Hand& hand) {
    int heartsCount = 0;
    int diamondsCount = 0;
    int clubsCount = 0;
    int spadesCount = 0;

    cout << "Checking for Flush...\n";
    for (const Card& card : hand.cards) {
        if (card.suit == 'H') heartsCount++;
        else if (card.suit == 'D') diamondsCount++;
        else if (card.suit == 'C') clubsCount++;
        else if (card.suit == 'S') spadesCount++;
    }

    if (heartsCount >= 5 || diamondsCount >= 5 || clubsCount >= 5 || spadesCount >= 5) {
        cout << "Got Flush...\n";
        return HandRank::Flush;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}