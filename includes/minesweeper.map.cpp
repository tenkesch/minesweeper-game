#include "minesweeper.map.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

#define HEIGHT 20
#define WIDTH 20

#define DIFF_EASY 0.06
#define DIFF_MEDIUM 0.12
#define DIFF_HARD 0.18

#define SYMBOL_MINE '@'

using namespace std;

Slot Field[HEIGHT][WIDTH] = {}; // public across all files with map.hpp

void generateMines();
void generateMineCounts();

bool inBorders(int i, int j) {
    return (i >= 0 && i < HEIGHT) && (j >= 0 && j < WIDTH);
}

void countMines(int i, int j) {
    for (int row = i - 1; row <= i + 1; row++)
        for (int col = j - 1; col <= j + 1; col++)
            if (inBorders(row, col) && Field[row][col].isMine)
                Field[i][j].mineCount++;
}

int main() {
    generateMines();
    generateMineCounts();

    // print Map
    cout << endl;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (Field[i][j].isMine)
                cout << SYMBOL_MINE << " ";
            else
                cout << Field[i][j].mineCount << " ";
        }
        cout << endl;
    }

    return 0;
}

void generateMines() {
    srand(time(NULL));

    const int desiredBombCount = HEIGHT * WIDTH * DIFF_HARD;
    auto bombCounter = 0;

    while (true)
        for (int i = 0; i < HEIGHT; i++)
            for (int j = 0; j < WIDTH; j++) {
                auto randomNum = (rand() % 100);
                // cout << randomNum << endl;

                if (!Field[i][j].isMine && (randomNum <= 2)) {
                    Field[i][j].isMine = true;
                    bombCounter++;
                }

                if (bombCounter == desiredBombCount) {
                    cout << "Bomb Counter: " << bombCounter << endl;
                    return;
                }
            }
}

void generateMineCounts() {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++) {
            countMines(i, j);
        }
}
