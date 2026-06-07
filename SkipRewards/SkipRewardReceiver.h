#pragma once

#include "../Deck.h"

class SkipRewardReceiver {
public:
    int grantBonusHand(int hand, int count = 1);
    void grantFreePlayingCard(Deck& deck);
};
