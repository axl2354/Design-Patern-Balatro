#pragma once

#include "SkipCommand.h"
#include "SkipRewardReceiver.h"
#include "../Deck.h"

class BonusHandCommand : public SkipCommand {
public:
    BonusHandCommand(SkipRewardReceiver& receiver, Deck& deck, int bonusCount = 1);
    void execute() override;
    EventType getEventType() const override;

private:
    SkipRewardReceiver& receiver;
    Deck& deck;
    int bonusCount;
};
