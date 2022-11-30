#include <stdlib.h>
#include <iostream>
#include "raylib.h"
#include "game.h"

int main(void)
{
    // Initialization
    Game game = {};
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        game.Update();
        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);
        game.Draw();

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}
