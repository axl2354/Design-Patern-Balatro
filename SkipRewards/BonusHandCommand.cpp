#include "BonusHandCommand.h"

BonusHandCommand::BonusHandCommand(SkipRewardReceiver& receiver, Hand& playerHand, Deck& deck, int bonusCount)
    : receiver(receiver), playerHand(playerHand), deck(deck), bonusCount(bonusCount) {
}

void BonusHandCommand::execute() {
    receiver.grantBonusHand(playerHand, deck, bonusCount);
}

EventType BonusHandCommand::getEventType() const {
    return EventType::BlindEnter;
}
