#include "base_tower.h"
#include "raylib.h"
#include <vector>
#include "bullet.h"
#include "raymath.h"
using namespace std;
void base_tower::Draw()
{
    DrawTextureEx(texture, position, rotation, scale, WHITE);
    DrawCircleLines(position.x + 32, position.y + 32, range, YELLOW);

    for (auto bullet : bullets)
    {

        bullet->Draw();
    }
}
void base_tower::Update(float deltaTime)
{
    bulletTimer += deltaTime;
    if (hasTarget)
    {
        if (bulletTimer >= 1.0f)
        {
            Vector2 bulletDirection = Vector2Normalize(Vector2Subtract(target->getPosition(), position));
            bullets.push_back(new Bullet({position.x+32, position.y+32}, bulletDirection));
            bulletTimer = 0.0f;
        }
    }
    for (auto bullet : bullets)
    {

        bullet->Update(deltaTime);
        
    }
}

base_tower::base_tower(Texture2D tex, Vector2 pos)
{
    texture = tex;
    position = pos;
    range = 128;
}
void base_tower::setTarget(Enemy* enemy)
{
    target = enemy;
    
}

void base_tower::setHasTarget(bool target)
{
    hasTarget = target;
    
}