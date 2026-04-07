#include "FiveOfAKindChecker.h"
HandRank FIveOfAKindChecker::check(const Hand& hand) {
    if (isFiveOfAKind(hand))
        return HandRank::FiveOfAKind;
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HighCard;
}