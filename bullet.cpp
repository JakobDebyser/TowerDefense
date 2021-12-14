#include "bullet.h"
#include "raymath.h"
Bullet::Bullet(Vector2 pos, Vector2 dir, Enemy *tar)
{
    position = pos;
    direction = dir;
    speed = 500.0f;
    target = tar;
}

void Bullet::Update(float deltaTime)
{
    Vector2 bullet_direction = Vector2Scale(Vector2Normalize(direction), speed * deltaTime);

    position = Vector2Add(position, bullet_direction);
}

void Bullet::Draw()
{
    DrawCircle(position.x + 32, position.y + 32, 5, BLACK);
    // LoadTexture();
}