#include "raylib.h"
#include "enemy.h"
#include "Base_Tower.h"

int main()
{
    InitWindow(1024, 768, "TowerDefense");
    Texture2D WorldMap = LoadTexture("textures/testmap.png");
    Texture2D towerTexture = LoadTexture("textures/tower.png");
    const int scale = 2;
    const float rotation{0};
    const Vector2 position{0,0};
    float deltaTime;
    base_tower towerTest{towerTexture, {0, 0}};
    Enemy enemy{};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        deltaTime = GetFrameTime();
        BeginDrawing();
        ClearBackground(WHITE);
        DrawTextureEx(WorldMap, position,rotation, scale, WHITE);

        enemy.Update(deltaTime);
        enemy.Draw();

        towerTest.Update(deltaTime);
        towerTest.Draw();

        EndDrawing();
    }

    return 0;
}
