#pragma once

class HandCount {
public:
    explicit HandCount(int maxCount = 3);

    void reset();
    bool consumePlay();
    void addPlays(int n);
    int getRemaining() const;
    bool isExhausted() const;

private:
    const int maxCount;
    int remainingCount;
};
