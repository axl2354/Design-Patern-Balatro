#include "SkipRewardReceiver.h"
#include <iostream>

void SkipRewardReceiver::grantBonusHand(Hand& playerHand, Deck& deck, int count) {
    std::cout << "Granting bonus hand reward...\n";
    for (int i = 0; i < count && !deck.empty(); ++i) {
        playerHand.cards.push_back(deck.dealCard());
    }
}

void SkipRewardReceiver::grantFreePlayingCard(Hand& playerHand, Deck& deck) {
    std::cout << "Granting free playing card reward...\n";
    if (!deck.empty()) {
        playerHand.cards.push_back(deck.dealCard());
    }
}
