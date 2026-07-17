#include "MS.map.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

#define SYMBOL_MINE '@'

using namespace std;

// public across all files with map.hpp
Slot Field[MAP_ROW_COUNT][MAP_COL_COUNT] = {};
DiffOptions Difficulty;

bool inBorders(int i, int j) {
    return (i >= 0 && i < MAP_ROW_COUNT) && (j >= 0 && j < MAP_COL_COUNT);
}

void countMines(int i, int j) {
    for (int row = i - 1; row <= i + 1; row++)
        for (int col = j - 1; col <= j + 1; col++)
            if (inBorders(row, col) && Field[row][col].isMine_)
                Field[i][j].mineCount_++;
}

void printMap() {
    cout << endl;
    for (int i = 0; i < MAP_ROW_COUNT; i++) {
        for (int j = 0; j < MAP_COL_COUNT; j++) {
            if (Field[i][j].isMine_)
                cout << SYMBOL_MINE << " ";
            else
                cout << Field[i][j].mineCount_ << " ";
        }
        cout << endl;
    }
}

void generateMines() {
    srand(time(NULL));

    const int desiredBombCount =
        MAP_ROW_COUNT * MAP_COL_COUNT * Difficulty.HARD_;
    auto bombCounter = 0;

    while (true)
        for (int i = 0; i < MAP_ROW_COUNT; i++)
            for (int j = 0; j < MAP_COL_COUNT; j++) {

                auto randomNum = (rand() % 100);

                if (!Field[i][j].isMine_ && (randomNum <= 2)) {
                    Field[i][j].isMine_ = true;

                    if (++bombCounter == desiredBombCount) {
                        cout << "Bomb Counter: " << bombCounter << endl;
                        return;
                    }
                }
            }
}

void SetupMap() {
    for (int i = 0; i < MAP_ROW_COUNT; i++)
        for (int j = 0; j < MAP_COL_COUNT; j++) {
            Field[i][j].createButton(i, j); // Create "button_" Rectangles

            countMines(i, j);
        }
}

void generateMap() {
    generateMines();
    SetupMap();
    printMap();
}
