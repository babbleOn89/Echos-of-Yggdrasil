#include <raylib.h>
#include "game.hpp"

int main()
{
    int windowWidth = 1600;
    int windowHeight = 400;

    InitWindow(windowWidth, windowHeight, "Stupid Wizards");

    SetTargetFPS(60);

    Game game;

    while(WindowShouldClose() == false)
    {
        game.Update();
        
        BeginDrawing();
        ClearBackground(BLACK);
        game.Draw();

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
