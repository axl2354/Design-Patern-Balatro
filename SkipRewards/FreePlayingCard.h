#pragma once

#include "SkipCommand.h"
#include "SkipRewardReceiver.h"
#include "Hand.h"
#include "Deck.h"

class FreePlayingCard : public SkipCommand {
public:
    FreePlayingCard(SkipRewardReceiver& receiver, Hand& playerHand, Deck& deck);
    void execute() override;
    EventType getEventType() const override;

private:
    SkipRewardReceiver& receiver;
    Hand& playerHand;
    Deck& deck;
};
