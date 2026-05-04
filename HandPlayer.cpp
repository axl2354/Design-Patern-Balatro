// HandPlayer.cpp
#include "HandPlayer.h"
#include <iostream>
#include <vector>
#include "Card.h"
#include "Hand.h"

Hand HandPlayer::playHand(Hand& hand) {
    Hand playedHand;  // Local variable - resets each call
    int select;       // Local variable
    int confirm = 1;  // Local variable - resets each call
    int cardsPlayed = 0; // Local variable to track number of cards played
    
    
    std::cout << "Player selects cards to play...\n";
    while(confirm == 1) {
        for(int i = 0; i < hand.cards.size(); ++i) {
    // TAMBAHAN BARU: Mencetak kartu ke terminal 
        std::cout << "Card " << (i + 1) << ": ";
        
        // Opsional: Mempercantik tampilan output untuk kartu wajah (J, Q, K, A)
        if (hand.cards[i].rank == 11) std::cout << "J";
        else if (hand.cards[i].rank == 12) std::cout << "Q";
        else if (hand.cards[i].rank == 13) std::cout << "K";
        else if (hand.cards[i].rank == 14) std::cout << "A";
        else std::cout << hand.cards[i].rank;

        std::cout << " of " << hand.cards[i].suit << "\n";
        // -------------------------------------------------
    }
        std::cin>> select;
        if (select >= 1 && select <= hand.cards.size()) {
            std::cout << "Card " << select << " selected.\n";
            playedHand.cards.push_back(hand.cards[select - 1]);
            hand.cards.erase(hand.cards.begin() + (select - 1)); 
            cardsPlayed++;
            if (cardsPlayed >= 5) {
                std::cout << "Maximum of 5 cards played.\n";
                break;
            }
            std::cout << "Select more cards? (1 for Yes, 0 for No): ";
            std::cin >> confirm;
            if (!confirm) {
                break;
            }
        } else {
            std::cout << "Invalid selection. Please select a card between 1 and " << hand.cards.size() << ".\n";
            std::cout << "Select more cards? (1 for Yes, 0 for No): ";
            std::cin >> confirm;
            if (!confirm) {
                break;
            }
        }
    }
    return playedHand;
}