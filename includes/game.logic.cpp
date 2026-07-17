#include "MS.map.hpp"
#include "raylib.h"
#include <iostream>
// box - type bomb, flag, normal

Vector2 findClosestBox(const int x, const int y);

void gameLogic() {
    // if (IsKeyDown(MOUSE_BUTTON_LEFT)) {
    if (IsKeyDown(KEY_A)) {
        Vector2 mousePosition = GetMousePosition();
        // TODO: find closest button to mouse pointer and then check if they
        // collide
        const Vector2 pos = findClosestBox(mousePosition.x, mousePosition.y);
        const int row = pos.x, col = pos.y;

        Field[row][col].reveal();
    }
}

Vector2 findClosestBox(const int x, const int y) {
    Vector2 ClosestBox = {(MAP_ORIGIN_X + SPOT_SIZE +
                           BUTTON_PADDING * SPOT_SIZE * MAP_COL_COUNT) /
                              x,
                          MAP_ORIGIN_Y + SPOT_SIZE +
                              (BUTTON_PADDING * SPOT_SIZE * MAP_ROW_COUNT) / y};

    return ClosestBox;
}
