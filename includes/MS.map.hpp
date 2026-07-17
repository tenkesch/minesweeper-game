#pragma once
#include "raylib.h"

#define MAP_ROW_COUNT 20
#define MAP_COL_COUNT 20
#define SPOT_SIZE 13
#define BUTTON_PADDING 2
constexpr float MAP_ORIGIN_X = 0.0f;
constexpr float MAP_ORIGIN_Y = 0.0f;

struct DiffOptions {
    const float EASY_ = 0.06, MEDIUM_ = 0.12, HARD_ = 0.18;
};

struct Slot {
    int mineCount_ = 0;
    bool isMine_ = false, isRevealed_ = false, isFlagged_ = false;
    Rectangle button_;

    bool reveal() { // should check "isFlagged_" before
        isRevealed_ = true;
        return isMine_;
    }

    void flag() {
        if (!isRevealed_)
            isFlagged_ = !isFlagged_;
    }
    Color getColorByMineCount() {
        if (isMine_)
            return RED;

        Color ColorByCloseness[9] = {WHITE, GREEN, YELLOW, ORANGE, PINK,
                                     BROWN, BLUE,  PURPLE, WHITE};
        return ColorByCloseness[mineCount_ - 1];
    }

    void createButton(int x, int y) {
        button_ = {MAP_ORIGIN_X + SPOT_SIZE + BUTTON_PADDING * SPOT_SIZE * x,
                   MAP_ORIGIN_Y + SPOT_SIZE + BUTTON_PADDING * SPOT_SIZE * y,
                   SPOT_SIZE, SPOT_SIZE};
    }
};

void generateMap();

extern Slot Field[MAP_ROW_COUNT][MAP_COL_COUNT];
extern DiffOptions Difficulty;
