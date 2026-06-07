#pragma once

#include "SkipCommand.h"
#include "SkipRewardReceiver.h"
#include "../Deck.h"
#include "../HandCount.h"

class BonusHandCommand : public SkipCommand {
public:
    BonusHandCommand(SkipRewardReceiver& receiver, HandCount& handCount, int bonusCount = 1);
    void execute() override;
    EventType getEventType() const override;

private:
    SkipRewardReceiver& receiver;
    HandCount& handCount;
    int bonusCount;
};
