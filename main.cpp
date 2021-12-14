#include "raylib.h"
#include "enemy.h"
#include "Base_Tower.h"
#include <vector>
#include "bullet.h"
using namespace std;
int main()
{
    InitWindow(1024, 768, "TowerDefense");
    Texture2D WorldMap = LoadTexture("textures/testmap.png");
    Texture2D towerTexture = LoadTexture("textures/tower.png");
    const int scale = 2;
    const float rotation{0};
    const Vector2 Map_position{0, 0};
    float deltaTime;
    base_tower towerTest{towerTexture, {128, 128}};
    vector<Enemy *> enemies;
    vector<base_tower *> towers;
    towers.push_back(new base_tower(towerTest));
    float spawnTimer{0};
    int spawnCount{0};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        deltaTime = GetFrameTime();
        BeginDrawing();
        ClearBackground(WHITE);
        DrawTextureEx(WorldMap, Map_position, rotation, scale, WHITE);
        spawnTimer += deltaTime;
        if (spawnTimer >= 1 && spawnCount < 1)
        {
            spawnTimer = 0;
            enemies.push_back(new Enemy());
            spawnCount++;
        }

        for (auto enemy : enemies)
        {
            enemy->Update(deltaTime);
            enemy->Draw();
        }
        for (auto tower : towers)
        {

            bool hasTarget{};
            for (auto enemy : enemies)
            {

                if (CheckCollisionCircleRec(tower->getPosition(), tower->getRange(), enemy->getCollisionRect()) && !hasTarget)
                {
                    tower->setTarget(enemy);
                    tower->setHasTarget(true);
                    hasTarget = true;
                }
            }
            if (hasTarget)
            {
                if (CheckCollisionCircleRec(tower->getPosition(), tower->getRange(), tower->getTarget()->getCollisionRect()))
                {
                    tower->setTarget({});
                    tower->setHasTarget(false);
                    hasTarget = false;
                }
            }

            tower->Update(deltaTime);
            tower->Draw();
        }

        EndDrawing();
    }

    return 0;
}
