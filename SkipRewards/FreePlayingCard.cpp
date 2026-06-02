#include "FreePlayingCard.h"

FreePlayingCard::FreePlayingCard(SkipRewardReceiver& receiver, Hand& playerHand, Deck& deck)
    : receiver(receiver), playerHand(playerHand), deck(deck) {
}

void FreePlayingCard::execute() {
    receiver.grantFreePlayingCard(playerHand, deck);
}

EventType FreePlayingCard::getEventType() const {
    return EventType::BlindClear;
}
