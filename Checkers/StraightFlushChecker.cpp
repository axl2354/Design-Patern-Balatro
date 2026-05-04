
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "StraightFlushChecker.h"
using namespace std;

static bool isConsecutive(const set<int>& ranks) {
    if (ranks.size() < 5) return false;
    vector<int> rankList(ranks.begin(), ranks.end());
    for (size_t i = 0; i + 4 < rankList.size(); ++i) {
        if (rankList[i + 4] - rankList[i] == 4) {
            return true;
        }
    }
    if (ranks.count(14) && ranks.count(2) && ranks.count(3) && ranks.count(4) && ranks.count(5)) {
        return true;
    }
    return false;
}

HandRank StraightFlushChecker::check(const Hand& hand) {
    cout << "Checking for Straight Flush...\n";
    map<char, set<int>> suitRanks;
    for (const Card& card : hand.cards) {
        suitRanks[card.suit].insert(card.rank);
    }

    for (const auto& entry : suitRanks) {
        if (isConsecutive(entry.second)) {
            cout << "Got Straight Flush...\n";
            return HandRank::StraightFlush;
        }
    }

    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}