#pragma once

#include "../Deck.h"

class SkipRewardReceiver {
public:
    void grantBonusHand(Deck& deck, int count = 1);
    void grantFreePlayingCard(Deck& deck);
};
