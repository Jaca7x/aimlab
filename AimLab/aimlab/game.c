#include "raylib.h"
#include "game.h"
#include <stdlib.h>

#define MAX_ALVO 8

static Rectangle alvo[MAX_ALVO];
static int points = 0;
static int screenWidth, screenHeight;

static void repositionRectangle(int i) {
    alvo[i].x = rand() % (screenWidth - (int)alvo[i].width);
    alvo[i].y = rand() % (screenHeight - (int)alvo[i].height);
}

void InitGame(int sw, int sh) {
    screenWidth = sw;
    screenHeight = sh;

    for (int i = 0; i < MAX_ALVO; i++) {
        alvo[i].width = 50;
        alvo[i].height = 50;
        repositionRectangle(i);
    }
}

void UpdateGame(void) {
    Vector2 mouse = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        for (int i = 0; i < MAX_ALVO; i++) {
            if (CheckCollisionPointRec(mouse, alvo[i])) {
                repositionRectangle(i);
                points++;
            }
        }
    }
}

void DrawGame(void) {
    BeginDrawing();
    ClearBackground(BLACK);

    for (int i = 0; i < MAX_ALVO; i++) {
        DrawRectangleRec(alvo[i], WHITE);
    }

    DrawText(TextFormat("Points: %d", points), 10, 10, 20, RED);
    EndDrawing();
}
