#include "raylib.h"
#include "aimlab/game.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Click Game");
    SetTargetFPS(60);

    InitGame(screenWidth, screenHeight);

    while (!WindowShouldClose()) {
        UpdateGame();
        DrawGame();
    }

    CloseWindow();
    return 0;
}
