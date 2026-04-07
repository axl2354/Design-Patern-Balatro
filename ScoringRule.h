#ifndef SCORINGSYSTEM_H
#define SCORINGSYSTEM_H

#include "PokerHandChecker.h"
#include "Hand.h"
#include <string>
#include <vector>

struct Score
{
    std::string handName;
    int chips;
    int mult;

    std::vector<int> scoringIndexes;
};
ScoringRule();
int scoreHand(const Hand& hand);
int convertRankToScore(HandRank rank);


#endif