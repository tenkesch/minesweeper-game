#include "MS.map.hpp"
#include "raylib.h"

void renderMap();

void renderScreen() {
    BeginDrawing();
    ClearBackground(BLACK); // visible color
    DrawText("MINESWEEPER HELL YEAHH", 20, 20, 10, PURPLE);

    renderMap();

    EndDrawing();
}

void renderMap() {
    for (int i = 0; i < MAP_ROW_COUNT; i++) {
        for (int j = 0; j < MAP_COL_COUNT; j++) {
            const auto [x, y, width, height] = Field[i][j].button_;

            if (!Field[i][j].isRevealed_) {

                DrawRectangle(
                    x, y, width, height,
                    Field[i][j].getColorByMineCount()); // TODO Make Field[]
                                                        // contain Rectangle
                continue;
            }

            // else show count number
        }
        // cout << endl;
    }
}
