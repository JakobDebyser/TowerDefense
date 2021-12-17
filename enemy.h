#ifndef _ENEMY_
#define _ENEMY_
#include "raylib.h"

class Enemy
{
public:
    Enemy(int difficultyLevel);
    Vector2 getPosition() { return position; }
    int getSpeed() { return speed; }
    int getHealth() { return health; }
    Vector2 getDestination() { return currentDestination; }
    void Update(float deltaTime,int &lives);
    void Draw();
    Rectangle getCollisionRect() { return collisionRect; };
    void takeDamage(int damage);
    bool IsAlive() { return Alive; }
    int getReward() { return reward;}

private:
    Texture2D texture{};
    Vector2 position{};
    Vector2 direction{};
    Rectangle collisionRect{};
    int speed{};
    int health{};
    int maxHealth{};
    Vector2 currentDestination{};
    Vector2 waypoints[8] = {{64, 576}, {256, 576}, {256, 640}, {576, 640}, {576, 384}, {320, 384}, {320, 128}, {640, 128}};
    void CalculateDirection(int index);
    int waypointIndex{0};
    bool Alive{true};
    int reward{5};
};

#endif // _ENEMY_