#ifndef _ENEMY_
#define _ENEMY_
#include "raylib.h"
class Enemy
{
public:
    Vector2 getPosition() { return position; }
    int getSpeed() { return speed; }
    int getHealth() { return health; }
    Vector2 getDestination() { return destination; }

private:
    Texture2D texture{};
    Vector2 position{};
    int speed{};
    int health{};
    Vector2 destination{};
};

#endif // _ENEMY_