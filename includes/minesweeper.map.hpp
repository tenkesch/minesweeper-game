#pragma once

struct Slot {
    int mineCount = 0;
    bool isMine = false, isRevealed = false, isFlagged = false;

    bool reveal() {
        if (isFlagged)
            return false;

        isRevealed = true;
        return isMine;
    }

    void flag() {
        if (!isRevealed)
            isFlagged = !isFlagged;
    }
};
