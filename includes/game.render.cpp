#include "MS.map.hpp"
#include "raylib.h"

#define SPOT_SIZE 13
#define PADDING 2
#define MAP_BEGIN_X 20
#define MAP_BEGIN_Y 40

void renderMap();

void renderScreen() {
    BeginDrawing();
    ClearBackground(BLACK); // visible color
    DrawText("MINESWEEPER HELL YEAHH", 20, 20, 10, PURPLE);

    renderMap();

    EndDrawing();
}

void renderMap() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (!Field[i][j].isRevealed_) {
                DrawRectangle(
                    MAP_BEGIN_X + SPOT_SIZE + PADDING * SPOT_SIZE * j,
                    MAP_BEGIN_Y + SPOT_SIZE + PADDING * SPOT_SIZE * i,
                    SPOT_SIZE, SPOT_SIZE,
                    ORANGE); // TODO: change Color for how close it is to bomb
                continue;
            }

            // else show count number
        }
        // cout << endl;
    }
}
