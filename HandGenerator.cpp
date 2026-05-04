// HandGenerator.cpp
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "HandGenerator.h"

Hand HandGenerator::generateHand() {
    std::cout << "Generating random hand...\n";
    Hand hand;
    
    // Inisialisasi random engine
    std::mt19937 gen(static_cast<unsigned int>(std::time(0)));
    std::uniform_int_distribution<> rankDist(2, 14); // Rank 2 sampai 14 (11=J, 12=Q, 13=K, 14=A)
    std::uniform_int_distribution<> suitDist(0, 3);  // 0-3 untuk indeks Suit
    char suits[] = {'H', 'D', 'C', 'S'}; // Hearts, Diamonds, Clubs, Spades

    // Menghasilkan 8 kartu random untuk tangan pemain
    for(int i = 0; i < 8; ++i) {
        Card randomCard;
        randomCard.rank = rankDist(gen);
        randomCard.suit = suits[suitDist(gen)];
        
        // TAMBAHAN BARU: Mencetak kartu ke terminal 
        std::cout << "Card " << (i + 1) << " generated: ";
        
        // Opsional: Mempercantik tampilan output untuk kartu wajah (J, Q, K, A)
        if (randomCard.rank == 11) std::cout << "J";
        else if (randomCard.rank == 12) std::cout << "Q";
        else if (randomCard.rank == 13) std::cout << "K";
        else if (randomCard.rank == 14) std::cout << "A";
        else std::cout << randomCard.rank;

        std::cout << " of " << randomCard.suit << "\n";
        // -------------------------------------------------

        hand.cards.push_back(randomCard);
    }

    std::cout << "Finished generating 8 cards.\n\n";
    return hand;
}