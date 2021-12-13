#include "raylib.h"

int main()
{
    InitWindow(1024, 768, "TowerDefense");
    Texture2D WorldMap = LoadTexture("textures/testmap.png");
    const int scale = 2;
    const float rotation{0};
    const Vector2 position{0,0};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawTextureEx(WorldMap, position,rotation, scale, WHITE);

        EndDrawing();
    }

    return 0;
}
