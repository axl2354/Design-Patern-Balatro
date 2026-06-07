#include "HandCount.h"

HandCount::HandCount(int maxCount)
    : maxCount(maxCount), remainingCount(maxCount) {
}

void HandCount::reset() {
    remainingCount = maxCount;
}

bool HandCount::consumePlay() {
    if (remainingCount <= 0) {
        return false;
    }
    --remainingCount;
    return true;
}

void HandCount::addPlays(int n) {
    if (n <= 0) return;
    remainingCount += n;
}

int HandCount::getRemaining() const {
    return remainingCount;
}

bool HandCount::isExhausted() const {
    return remainingCount <= 0;
}
