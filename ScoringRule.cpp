// ScoringRule.cpp
#include "ScoringRule.h"
#include <iostream>

ScoringRule::ScoringRule() {
    // Merangkai rantai pengecekan dari yang terkuat ke terlemah
    flushFive.setNext(&flushHouse);
    flushHouse.setNext(&fiveOfAKind);
    fiveOfAKind.setNext(&royalFlush);
    royalFlush.setNext(&straightFlush);
    straightFlush.setNext(&fourOfAKind);
    fourOfAKind.setNext(&fullHouse);
    fullHouse.setNext(&flush);
    flush.setNext(&straight);
    straight.setNext(&threeOfAKind);
    threeOfAKind.setNext(&twoPair);
    twoPair.setNext(&pairChecker);
    pairChecker.setNext(&highCard);

    // Titik awal
    rootChecker = &flushFive;
}

int ScoringRule::scoreHand(const Hand& hand) {
    std::cout << "Calculating hand score...\n";
    HandRank rank = rootChecker->check(hand);
    return convertRankToScore(rank);
}

int ScoringRule::convertRankToScore(HandRank rank) {
    // Hanya dummy konversi, High Card nilainya 5
    switch (rank) {
        case HandRank::FLUSH_FIVE: return 50;
        case HandRank::HIGH_CARD: default: return 5;
    }
}