#include "FreePlayingCard.h"

FreePlayingCard::FreePlayingCard(SkipRewardReceiver& receiver, Deck& deck)
    : receiver(receiver), deck(deck) {
}

void FreePlayingCard::execute() {
    receiver.grantFreePlayingCard(deck);
}

EventType FreePlayingCard::getEventType() const {
    return EventType::Instant;
}
