#include "raylib.h"
#include "enemy.h"
#include "Base_Tower.h"
#include <vector>
#include "bullet.h"
#include "start_button.h"
#include "tower_button.h"
#include"mouseObject.h"
#include"mouseStatus.h"

using namespace std;
int main()
{

    //TODO: variabelen in juiste/logische volgorde zetten
    float window_Width{1024};
    float window_Height{768};
    InitWindow(window_Width, window_Height, "TowerDefense");
    Texture2D WorldMap = LoadTexture("textures/testmap.png");
    Texture2D towerTexture = LoadTexture("textures/tower.png");
    Texture2D NextWave = LoadTexture("textures/nextWave.png");
    Texture2D basicTowerButtonTexture = LoadTexture("textures/nextWave.png"); //texture vervangen
    const int scale = 2;
    const float rotation{0};
    const Vector2 Map_position{0, 0};
    float deltaTime;
    base_tower towerTest{towerTexture, {128, 128}};
    vector<Enemy *> enemies;
    vector<base_tower *> towers;
    start_button start{NextWave, {840, 64}};
    TowerButton basicTower{basicTowerButtonTexture, {840, 128}};
    MouseObject mouseObject{};

    towers.push_back(new base_tower(towerTest));
    float spawnTimer{0};
    int spawnCount{0};
    bool spawningEnemies{};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        deltaTime = GetFrameTime();
        BeginDrawing();
        ClearBackground(WHITE);
        DrawTextureEx(WorldMap, Map_position, rotation, scale, WHITE);
        if (start.isClicked())
        {
            spawningEnemies = true;
            spawnCount = 0;
        }
        if (spawningEnemies)
        {
            spawnTimer += deltaTime;
            if (spawnTimer >= 1 && spawnCount < 6)
            {
                spawnTimer = 0;
                enemies.push_back(new Enemy());
                spawnCount++;
                if (spawnCount >= 6)
                {
                    spawningEnemies = false;
                }
            }
        }

        int EnemyIndex{0};
        for (auto enemy : enemies)
        {

            if (enemy->IsAlive())
            {
                enemy->Update(deltaTime);
                enemy->Draw();
            }
            else
            {
                enemies.erase(enemies.begin() + EnemyIndex);
            }
            EnemyIndex++;
        }
        for (auto tower : towers)
        {

            for (auto enemy : enemies)
            {

                if (CheckCollisionCircleRec(tower->getPosition(), tower->getRange(), enemy->getCollisionRect()) && !tower->getHasTarget() && enemy->IsAlive())
                {
                    tower->setTarget(enemy);
                    tower->setHasTarget(true);
                }
            }
            if (tower->getHasTarget())
            {
                if (!CheckCollisionCircleRec(tower->getPosition(), tower->getRange(), tower->getTarget()->getCollisionRect()) && !tower->getTarget()->IsAlive())
                {
                    tower->setTarget({});
                    tower->setHasTarget(false);
                }
            }

            tower->Update(deltaTime, window_Width, window_Height);
            tower->Draw();
        }

        //MENU
        if(basicTower.isClicked()){
            mouseObject.setStatus(mouseStatus::BUILDING_BASIC_TOWER);
        }


        start.Draw();
        basicTower.Draw();

        mouseObject.Update(deltaTime);
        mouseObject.Draw();

        EndDrawing();
    }
    UnloadTexture(WorldMap);
    UnloadTexture(towerTexture);
    UnloadTexture(NextWave);
    UnloadTexture(basicTowerButtonTexture);

    return 0;
}
