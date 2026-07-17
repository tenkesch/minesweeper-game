#include "MS.map.hpp"
#include "raylib.h"

typedef struct Button {
    const Vector2 mouse = GetMousePosition();

    int col = (int)((mouse.x - MAP_ORIGIN_X) / SPOT_SIZE);
    int row = (int)((mouse.y - MAP_ORIGIN_Y) / SPOT_SIZE);

    bool insideGrid =
        (col >= 0 && col < MAP_COL_COUNT && row >= 0 && row < MAP_ROW_COUNT);

    void isPressed() {
        if (!IsKeyPressed(MOUSE_BUTTON_LEFT))
            return;

        // TODO : Click logic
        if (insideGrid && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            // (row, col) is the clicked cell
            // grid[row][col] = /* whatever your "pressed" logic is */;
        }

        // if (CheckCollisionPointRec(GetMousePosition(), )) //FIXME
    }
};
