#include "MS.map.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

#define SYMBOL_MINE '@'

using namespace std;

// public across all files with map.hpp
Slot Field[HEIGHT][WIDTH] = {};
DiffOptions Difficulty;

bool inBorders(int i, int j) {
    return (i >= 0 && i < HEIGHT) && (j >= 0 && j < WIDTH);
}

void countMines(int i, int j) {
    for (int row = i - 1; row <= i + 1; row++)
        for (int col = j - 1; col <= j + 1; col++)
            if (inBorders(row, col) && Field[row][col].isMine_)
                Field[i][j].mineCount_++;
}

void printMap() {
    cout << endl;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
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

    const int desiredBombCount = HEIGHT * WIDTH * Difficulty.HARD_;
    auto bombCounter = 0;

    while (true)
        for (int i = 0; i < HEIGHT; i++)
            for (int j = 0; j < WIDTH; j++) {
                auto randomNum = (rand() % 100);
                // cout << randomNum << endl;

                if (!Field[i][j].isMine_ && (randomNum <= 2)) {
                    Field[i][j].isMine_ = true;

                    if (++bombCounter == desiredBombCount) {
                        cout << "Bomb Counter: " << bombCounter << endl;
                        return;
                    }
                }
            }
}

void generateMineCounts() {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            countMines(i, j);
}

void generateMap() {
    generateMines();
    generateMineCounts();
    printMap();
}
