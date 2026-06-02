#include "BonusHandCommand.h"

BonusHandCommand::BonusHandCommand(SkipRewardReceiver& receiver, Deck& deck, int bonusCount)
    : receiver(receiver), deck(deck), bonusCount(bonusCount) {
}

void BonusHandCommand::execute() {
    receiver.grantBonusHand(deck, bonusCount);
}

EventType BonusHandCommand::getEventType() const {
    return EventType::BlindEnter;
}
