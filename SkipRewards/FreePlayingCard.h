#pragma once

#include "SkipCommand.h"
#include "SkipRewardReceiver.h"
#include "../Deck.h"

class FreePlayingCard : public SkipCommand {
public:
    FreePlayingCard(SkipRewardReceiver& receiver, Deck& deck);
    void execute() override;
    EventType getEventType() const override;

private:
    SkipRewardReceiver& receiver;
    Deck& deck;
};
