// HandGenerator.cpp
#include <iostream>
#include "HandGenerator.h"

Hand HandGenerator::generateHand() {
    std::cout << "Generating cards for player...\n"; // [cite: 344]
    Hand hand;
    hand.value = 6; // Dummy simulate flush [cite: 344]
    return hand;
}