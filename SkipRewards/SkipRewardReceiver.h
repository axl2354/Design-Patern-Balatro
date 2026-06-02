#pragma once

#include "Hand.h"
#include "Deck.h"

class SkipRewardReceiver {
public:
    void grantBonusHand(Hand& playerHand, Deck& deck, int count = 1);
    void grantFreePlayingCard(Hand& playerHand, Deck& deck);
};
