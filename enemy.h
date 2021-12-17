#ifndef _ENEMY_
#define _ENEMY_
#include "raylib.h"

class Enemy
{
public:
    Enemy(int difficultyLevel);
    Enemy(Texture2D texture, int difficulty);
    Vector2 getPosition() { return position; }
    int getSpeed() { return speed; }
    int getHealth() { return health; }
    Vector2 getDestination() { return currentDestination; }
   virtual void Update(float deltaTime,int &lives);
    virtual void Draw();
    Rectangle getCollisionRect() { return collisionRect; };
    void takeDamage(int damage);
    bool IsAlive() { return Alive; }
    int getReward() { return reward;}

protected:
   Texture2D texture{LoadTexture("textures/enemy.png")};
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
    float rotation{0};
};

#endif // _ENEMY_