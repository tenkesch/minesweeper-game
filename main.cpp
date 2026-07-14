#include "includes/MS.map.hpp"
#include "includes/libs.hpp"
#include "raylib.h"
#include <iostream>
#include <memory>

int main() {
    // setup
    []() {
        const auto WindowWidth = 800, WindowHeight = 600, maxFPS = 60;
        const auto windowName = "minesweeper";

        generateMap();
        InitWindow(WindowWidth, WindowHeight, windowName);
        SetTargetFPS(maxFPS);
    }();

    while (!WindowShouldClose()) {
        gameLogic();
        renderScreen();
    }

    CloseWindow();
    return 0;
}
