#pragma once

#define HEIGHT 20
#define WIDTH 20

struct DiffOptions {
    const float EASY_ = 0.06, MEDIUM_ = 0.12, HARD_ = 0.18;
};

struct Slot {
    int mineCount_ = 0;
    bool isMine_ = false, isRevealed_ = false, isFlagged_ = false;

    bool reveal() { // check isFlagged_ before
        isRevealed_ = true;
        return isMine_;
    }

    void flag() {
        if (!isRevealed_)
            isFlagged_ = !isFlagged_;
    }
};

void generateMap();

extern Slot Field[HEIGHT][WIDTH];
extern DiffOptions Difficulty;
