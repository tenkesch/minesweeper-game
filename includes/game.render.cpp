#include "libs.hpp"
#include "raylib.h"

int ballX = 0, ballY = 0;
void renderScreen() {
    BeginDrawing();
    ClearBackground(BLACK); // visible color
    DrawText("MINESWEEPER HELL YEAHH", 20, 20, 10, PURPLE);

    EndDrawing();
}
