#ifndef _BOSS_ENEMY_H
#define _BOSS_ENEMY_H
#include "enemy.h"
#include "raylib.h"
class bossEnemy : public Enemy
{

public:
    virtual void Update(float deltaTime, int &lives) override;
    bossEnemy(Texture2D tex,int difficulty);
    virtual void Draw()override;
protected:
    Texture2D texture{LoadTexture("textures/boss.png")};
    Rectangle collisionRect{};
    Vector2 position{};
    int speed{};
    int health{};
    int maxHealth{};
    Vector2 currentDestination{};
    Vector2 waypoints[8] = {{64, 576}, {256, 576}, {256, 640}, {576, 640}, {576, 384}, {320, 384}, {320, 128}, {640, 128}};
    void CalculateDirection(int index);
    int waypointIndex{0};
    bool Alive{true};
    int reward{5};
    float rotation{0};
};

#endif