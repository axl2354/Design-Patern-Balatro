// Hand.h
#pragma once

enum HandRank {
    HighCard,
    Pair,
    TwoPair,
    ThreeOfAKind,
    Straight,
    Flush,
    FullHouse,
    FourOfAKind,
    StraightFlush,
    RoyalFlush,
    FiveOfAKind
};
struct Hand {
    int value = 0; // Dummy data [cite: 341]
};