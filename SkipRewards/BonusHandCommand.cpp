#include "BonusHandCommand.h"

BonusHandCommand::BonusHandCommand(SkipRewardReceiver& receiver, HandCount& handCount, int bonusCount)
    : receiver(receiver), handCount(handCount), bonusCount(bonusCount) {
}

void BonusHandCommand::execute() {
    handCount.addPlays(bonusCount);
    receiver.grantBonusHand(handCount.getRemaining(), bonusCount);
}

EventType BonusHandCommand::getEventType() const {
    return EventType::BlindEnter;
}
