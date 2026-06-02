// Deck.cpp
#include "Deck.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <cassert>

static const char s_suits[4] = {'H', 'D', 'C', 'S'};
static const int s_ranks[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

Deck::Deck() {
    reset();
}

void Deck::reset() {
    cards.clear();
    cards.reserve(52);
    for (char suit : s_suits) {
        for (int rank : s_ranks) {
            cards.push_back(Card{rank, suit});
        }
    }
}

void Deck::shuffle() {
    std::mt19937 engine(static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    std::shuffle(cards.begin(), cards.end(), engine);
}

Card Deck::dealCard() {
    assert(!cards.empty() && "Cannot deal from an empty deck");
    Card topCard = cards.back();
    cards.pop_back();
    return topCard;
}

Hand Deck::dealHand(int count) {
    Hand hand;
    count = std::min(count, static_cast<int>(cards.size()));
    for (int i = 0; i < count; ++i) {
        hand.cards.push_back(dealCard());
    }
    return hand;
}

bool Deck::empty() const {
    return cards.empty();
}

int Deck::size() const {
    return static_cast<int>(cards.size());
}

void Deck::returnCard(const Card& card) {
    cards.push_back(card);
}

void Deck::returnHand(const Hand& hand) {
    for (const Card& card : hand.cards) {
        returnCard(card);
    }
}
