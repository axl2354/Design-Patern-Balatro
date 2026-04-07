#include "ScoringRule.h"
#include "Hand.h"
#include <map>
#include <algorithm>
using namespace std;


int scoreHand(const Hand& hand){

}
int convertRankToScore(HandRank rank){

}
Score ScoringSystem::evaluateHand(const Hand &hand)
{
    Score result = {"", 0, 1};
    map<int, int> rankCount;

    const vector<Card> &cards = hand.getCards();

    for (const Card &c : cards)
        rankCount[c.rank]++;

    bool three = false;
    bool four = false;
    int pairs = 0;

    for (auto &r : rankCount)
    {
        if (r.second == 2)
            pairs++;
        if (r.second == 3)
            three = true;
        if (r.second == 4)
            four = true;
    }

    bool flush = true;
    Suit firstSuit = cards[0].suit;

    for (const Card &c : cards)
    {
        if (c.suit != firstSuit)
        {
            flush = false;
            break;
        }
    }

    vector<int> ranks;
    for (const Card &c : cards)
        ranks.push_back(c.rank);

    sort(ranks.begin(), ranks.end());

    bool straight = true;
    for (int i = 1; i < ranks.size(); i++)
    {
        if (ranks[i] != ranks[i - 1] + 1)
        {
            straight = false;
            break;
        }
    }

    // HAND TYPE
    if (straight && flush)
        result = {"Straight Flush", 100, 8};

    else if (four)
        result = {"Four of a Kind", 60, 7};

    else if (three && pairs == 1)
        result = {"Full House", 40, 4};

    else if (flush)
        result = {"Flush", 35, 4};

    else if (straight)
        result = {"Straight", 30, 4};

    else if (three)
        result = {"Three of a Kind", 30, 3};

    else if (pairs == 2)
        result = {"Two Pair", 20, 2};

    else if (pairs == 1)
        result = {"Pair", 10, 2};

    else
        result = {"High Card", 5, 1};

    result.scoringIndexes.clear();

    if (result.handName == "Pair")
    {
        for (auto &r : rankCount)
            if (r.second == 2)
                for (int i = 0; i < cards.size(); i++)
                    if (cards[i].rank == r.first)
                        result.scoringIndexes.push_back(i);
    }

    else if (result.handName == "Two Pair")
    {
        for (auto &r : rankCount)
            if (r.second == 2)
                for (int i = 0; i < cards.size(); i++)
                    if (cards[i].rank == r.first)
                        result.scoringIndexes.push_back(i);
    }

    else if (result.handName == "Three of a Kind")
    {
        for (auto &r : rankCount)
            if (r.second == 3)
                for (int i = 0; i < cards.size(); i++)
                    if (cards[i].rank == r.first)
                        result.scoringIndexes.push_back(i);
    }

    else if (result.handName == "Four of a Kind")
    {
        for (auto &r : rankCount)
            if (r.second == 4)
                for (int i = 0; i < cards.size(); i++)
                    if (cards[i].rank == r.first)
                        result.scoringIndexes.push_back(i);
    }

    else if (result.handName == "Full House")
    {
        for (auto &r : rankCount)
            if (r.second == 3 || r.second == 2)
                for (int i = 0; i < cards.size(); i++)
                    if (cards[i].rank == r.first)
                        result.scoringIndexes.push_back(i);
    }

    else if (result.handName == "Straight" || result.handName == "Flush" || result.handName == "Straight Flush")
    {
        for (int i = 0; i < cards.size(); i++)
            result.scoringIndexes.push_back(i);
    }

    else if (result.handName == "High Card")
    {
        int highest = 0;
        int index = 0;

        for (int i = 0; i < cards.size(); i++)
        {
            if (cards[i].rank > highest)
            {
                highest = cards[i].rank;
                index = i;
            }
        }

        result.scoringIndexes.push_back(index);
    }

    for (int index : result.scoringIndexes)
        result.chips += getCardChips(cards[index]);
    
    return result;
}