
#include <iostream>
#include <set>
#include <vector>
#include "StraightChecker.h"
using namespace std;

HandRank StraightChecker::check(const Hand& hand) {
    cout << "Checking for Straight...\n";
    set<int> ranks;
    for (const Card& card : hand.cards) {
        ranks.insert(card.rank);
    }
    
    // Check for straight: 5 consecutive ranks
    vector<int> rankList(ranks.begin(), ranks.end());
    for (size_t i = 0; i + 4 < rankList.size(); ++i) {
        if (rankList[i+4] - rankList[i] == 4) {
            cout << "Got Straight...\n";
            return HandRank::Straight;
        }
    }
    
    // Special case for A-2-3-4-5 straight
    if (ranks.count(14) && ranks.count(2) && ranks.count(3) && ranks.count(4) && ranks.count(5)) {
        cout << "Got Straight (A-2-3-4-5)...\n";
        return HandRank::Straight;
    }
    
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HighCard;
}