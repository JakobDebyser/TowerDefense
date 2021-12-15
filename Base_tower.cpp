#include "base_tower.h"
#include "raylib.h"
#include <vector>
#include "bullet.h"
#include "raymath.h"
using namespace std;
void base_tower::Draw()
{
    DrawTextureEx(texture, position, rotation, scale, WHITE);
    if (isClicked)
    {
        DrawCircleLines(position.x + 32, position.y + 32, range, YELLOW);
    }

    for (auto bullet : bullets)
    {

        bullet->Draw();
    }
}
void base_tower::Update(float deltaTime, float window_Width, float window_Height)
{
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(GetMousePosition(), {position.x, position.y, static_cast<float>(texture.width * 2), static_cast<float>(texture.height * 2)}))
        {
            isClicked = true;
        }
        else
        {
            isClicked = false;
        }
    }

    bulletTimer += deltaTime;
    if (hasTarget)
    {
        if (bulletTimer >= 1.0f)
        {
            Vector2 bulletDirection = Vector2Normalize(Vector2Subtract(target->getPosition(), position));
            bullets.push_back(new Bullet({position.x, position.y}, bulletDirection, target));
            bulletTimer = 0.0f;
        }
    }
    int bulletIndex{0};
    for (auto bullet : bullets)
    {

        bullet->Update(deltaTime);
        if (CheckCollisionCircleRec(bullet->GetPosition(), 5.f, bullet->GetTarget()->getCollisionRect()))
        {
            bullet->GetTarget()->takeDamage(power);
            bullets.erase(bullets.begin() + bulletIndex);
            if (!bullet->GetTarget()->IsAlive())
            {
                target = {};
                hasTarget = false;
            }
        }
        if (bullet->GetPosition().x < 0 || bullet->GetPosition().y < 0 || bullet->GetPosition().x > window_Width || bullet->GetPosition().y > window_Height)
        {
            bullets.erase(bullets.begin() + bulletIndex);
        }
        bulletIndex++;
    }
}

base_tower::base_tower(Texture2D tex, Vector2 pos)
{
    texture = tex;
    position = pos;
    range = 128;
    power = 1;
}
base_tower::base_tower(Vector2 pos) : texture{LoadTexture("textures/tower.png")}, position{pos}
{
    range = 128;
    power = 1;
}
void base_tower::setTarget(Enemy *enemy)
{
    target = enemy;
}

void base_tower::setHasTarget(bool target)
{
    hasTarget = target;
}