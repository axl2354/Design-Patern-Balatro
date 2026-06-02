// HandGenerator.cpp
#include <iostream>
#include "HandGenerator.h"
#include "Deck.h"

Hand HandGenerator::generateHand(Deck& deck) {
    std::cout << "Generating random hand from deck...\n";
    deck.shuffle();

    Hand hand = deck.dealHand(8);
    std::cout << "Finished generating 8 cards.\n\n";
    return hand;
}