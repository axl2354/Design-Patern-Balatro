#include "SkipRewardReceiver.h"
#include <iostream>
#include <random>

static std::string printCard(const Card& card) {
    if (card.rank == 11) return "J" + std::string(1, card.suit);
    if (card.rank == 12) return "Q" + std::string(1, card.suit);
    if (card.rank == 13) return "K" + std::string(1, card.suit);
    if (card.rank == 14) return "A" + std::string(1, card.suit);
    return std::to_string(card.rank) + card.suit;
}

int SkipRewardReceiver::grantBonusHand(int hand, int count) {
    std::cout << "Granting bonus hand reward: " << count << " additional hand(s).\n";
    return hand + count;
}

void SkipRewardReceiver::grantFreePlayingCard(Deck& deck) {
    std::cout << "Granting free playing card reward...\n";

    const char suits[] = {'H', 'D', 'C', 'S'};
    const int ranks[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    std::vector<Card> candidates;
    candidates.reserve(5);

    std::mt19937 gen(static_cast<unsigned int>(std::random_device{}()));
    std::uniform_int_distribution<> suitDist(0, 3);
    std::uniform_int_distribution<> rankDist(0, 12);
    std::uniform_int_distribution<> choiceDist(0, 4);

    for (int i = 0; i < 5; ++i) {
        Card card;
        card.rank = ranks[rankDist(gen)];
        card.suit = suits[suitDist(gen)];
        candidates.push_back(card);
        std::cout << "  Option " << (i + 1) << ": " << printCard(card) << "\n";
    }
    std::cout << "Select a free playing card to add to the deck (1-5): ";
    int chosenIndex;
    std::cin >> chosenIndex;
    while (chosenIndex < 1 || chosenIndex > 5) {
        std::cout << "Invalid choice. Please select a number between 1 and 5: ";
        std::cin >> chosenIndex;
    }
    Card chosenCard = candidates[chosenIndex - 1];
    deck.returnCard(chosenCard);

    std::cout << "Chosen free playing card added to deck: " << printCard(chosenCard) << "\n";
}
