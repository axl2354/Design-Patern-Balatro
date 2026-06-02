#pragma once

#include <vector>
#include "Card.h"
#include "Hand.h"

class Deck {
public:
    Deck();
    void reset();
    void shuffle();
    Card dealCard();
    Hand dealHand(int count);
    void returnCard(const Card& card);
    void returnHand(const Hand& hand);
    bool empty() const;
    int size() const;

private:
    std::vector<Card> cards;
};
