
#include <iostream>
#include "FourOfAKindChecker.h"
using namespace std;

HandRank FourOfAKindChecker::check(const Hand& hand) {
    int AceCount = 0;
    int twoCount = 0;
    int threeCount = 0;
    int fourCount = 0;
    int fiveCount = 0;
    int sixCount = 0;
    int sevenCount = 0;
    int eightCount = 0;
    int nineCount = 0;
    int tenCount = 0;
    int JackCount = 0;
    int QueenCount = 0;
    int KingCount = 0;

    cout << "Checking for Four of a Kind...\n";
    for (const Card& card : hand.cards) {
        if (card.rank == 14) AceCount++;
        else if (card.rank == 2) twoCount++;
        else if (card.rank == 3) threeCount++;
        else if (card.rank == 4) fourCount++;
        else if (card.rank == 5) fiveCount++;
        else if (card.rank == 6) sixCount++;
        else if (card.rank == 7) sevenCount++;
        else if (card.rank == 8) eightCount++;
        else if (card.rank == 9) nineCount++;
        else if (card.rank == 10) tenCount++;
        else if (card.rank == 11) JackCount++;
        else if (card.rank == 12) QueenCount++;
        else if (card.rank == 13) KingCount++;
    }

    if (AceCount >= 4 || twoCount >= 4 || threeCount >= 4 || fourCount >= 4 || fiveCount >= 4 ||
        sixCount >= 4 || sevenCount >= 4 || eightCount >= 4 || nineCount >= 4 || tenCount >= 4 ||
        JackCount >= 4 || QueenCount >= 4 || KingCount >= 4) {
        cout << "Got Four of a Kind...\n";
        return HandRank::FourOfAKind;
    }

    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}