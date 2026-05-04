
#include <iostream>
#include <map>
#include <set>
#include "RoyalFlushChecker.h"
using namespace std;

HandRank RoyalFlushChecker::check(const Hand& hand) {
    cout << "Checking for Royal Flush...\n";
    map<char, set<int>> suitRanks;
    for (const Card& card : hand.cards) {
        suitRanks[card.suit].insert(card.rank);
    }

    for (const auto& entry : suitRanks) {
        const set<int>& ranks = entry.second;
        if (ranks.count(10) && ranks.count(11) && ranks.count(12) && ranks.count(13) && ranks.count(14)) {
            cout << "Got Royal Flush...\n";
            return HandRank::RoyalFlush;
        }
    }

    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}