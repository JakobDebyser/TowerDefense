#include "enemy.h"
#include "raymath.h"
#include <math.h>

Enemy::Enemy() : position{64, -64},
                 speed{100},
                 health{5},
                 maxHealth{5}
{
    //collisionRect={static_cast<float>(texture.width),static_cast<float>(texture.height)};
    collisionRect = {position.x, position.y, 25.f, 25.f};
}

void Enemy::Update(float deltaTime)
{

    collisionRect = {position.x, position.y, 25.f, 25.f};

    CalculateDirection(waypointIndex);
    direction = Vector2Scale(direction, speed * deltaTime);
    position = Vector2Add(position, direction);

    if (Vector2Distance(position, waypoints[waypointIndex]) < 2)
    {
        waypointIndex++;
        if (waypointIndex >= 8)
        {

            //TODO enemy reach base
            speed = 0;
        }
    }
}

void Enemy::CalculateDirection(int index)
{
    direction = Vector2Subtract(waypoints[index], position);
    direction = Vector2Normalize(direction);
}

void Enemy::Draw()
{
    //todo texture width and height replace
    DrawRectangle(position.x + 20, position.y + 20, 25, 25, RED);
    DrawRectangle(position.x + 20, position.y + 5, 25, 5, RED);
    DrawRectangle(position.x + 20, position.y + 5, health *25 /maxHealth, 5, GREEN);
}
void Enemy::takeDamage(int damage)
{

    health -= damage;
    if (health <= 0)
    {
        Alive = false;
    }
}