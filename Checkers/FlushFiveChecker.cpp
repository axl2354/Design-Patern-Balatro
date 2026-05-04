#include <iostream>
#include "FlushFiveChecker.h"
using namespace std;
HandRank FlushFiveChecker::check(const Hand& hand) {
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
    int heartsCount = 0;
    int diamondsCount = 0;
    int clubsCount = 0;
    int spadesCount = 0;
    cout << "Checking for Flush Five...\n";
    for (const Card& card : hand.cards) {
        if (card.suit == 'H') heartsCount++;
        else if (card.suit == 'D') diamondsCount++;
        else if (card.suit == 'C') clubsCount++;
        else if (card.suit == 'S') spadesCount++;

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
    
    if ((heartsCount >= 5 || diamondsCount >= 5 || clubsCount >= 5 || spadesCount >= 5)&&(AceCount == 5 || twoCount == 5 || threeCount == 5 || fourCount == 5 || fiveCount == 5 ||
         sixCount == 5 || sevenCount == 5 || eightCount == 5 || nineCount == 5 || tenCount == 5 ||
         JackCount == 5 || QueenCount == 5 || KingCount == 5)) {
        cout << "Got Flush Five...\n";
        return HandRank::FlushFive;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}