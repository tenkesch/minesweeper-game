#include "includes/libs.hpp"
#include "raylib.h"
#include <iostream>
#include <memory>

std::unique_ptr<Unit> playerUnit;

int main() {
    // setup
    []() {
        const auto WindowWidth = 800, WindowHeight = 600, maxFPS = 60;
        const auto windowName = "minesweeper";

        InitWindow(WindowWidth, WindowHeight, windowName);
        SetTargetFPS(maxFPS);
    }();

    playerUnit = makeUnit("Goblin", 20, 100);
    while (!WindowShouldClose()) {
        gameLogic();
        renderScreen();
    }

    CloseWindow();
    return 0;
}
