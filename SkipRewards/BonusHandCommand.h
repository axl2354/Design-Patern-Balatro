#pragma once

#include "SkipCommand.h"
#include "SkipRewardReceiver.h"
#include "Hand.h"
#include "Deck.h"

class BonusHandCommand : public SkipCommand {
public:
    BonusHandCommand(SkipRewardReceiver& receiver, Hand& playerHand, Deck& deck, int bonusCount = 1);
    void execute() override;
    EventType getEventType() const override;

private:
    SkipRewardReceiver& receiver;
    Hand& playerHand;
    Deck& deck;
    int bonusCount;
};
