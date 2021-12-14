#include "bullet.h"
#include "raymath.h"
Bullet::Bullet(Vector2 pos, Vector2 dir)
{
    position = pos;
    direction = dir;
    speed = 500.0f;
}

void Bullet::Update(float deltaTime)
{
    direction = Vector2Scale(Vector2Normalize(direction), speed*deltaTime);

    position = Vector2Add(position, direction);
}

void Bullet::Draw()
{
    DrawCircle(position.x,position.y,5,BLACK);
    // LoadTexture();
}