#include "enemy.h"
#include "raymath.h"
#include <math.h>

Enemy::Enemy() : position{64, -64},
                 speed{100},
                 health{2},
                 maxHealth{2}

{
    // collisionRect={static_cast<float>(texture.width),static_cast<float>(texture.height)};
    collisionRect = {position.x, position.y, 30.f, 30.f};
}

void Enemy::Update(float deltaTime, int &lives)
{

    collisionRect = {position.x, position.y, 30.f, 30.f};

    CalculateDirection(waypointIndex);
    direction = Vector2Scale(direction, speed * deltaTime);
    position = Vector2Add(position, direction);

    if (Vector2Distance(position, waypoints[waypointIndex]) < 2)
    {
        waypointIndex++;
        if (waypointIndex >= 8)
        {

            // TODO enemy reach base
            speed = 0;
            lives--;
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
    // todo texture width and height replace
    if (waypointIndex < 8)
    {
        DrawRectangle(position.x +18, position.y+18, 30, 30, RED);

        //healtbar
        DrawRectangle(position.x + 18, position.y + 5, 30, 5, RED);
        DrawRectangle(position.x + 18, position.y + 5, health * 30 / maxHealth, 5, GREEN);
    }
}
void Enemy::takeDamage(int damage)
{

    health -= damage;
    if (health <= 0)
    {
        Alive = false;
    }
}