#ifndef SCORINGSYSTEM_H
#define SCORINGSYSTEM_H

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
class ScoringSystem
{
public:
    static std::vector<IModifier*> modifiers;
    static Score evaluateHand(const Hand& hand);
};

#endif