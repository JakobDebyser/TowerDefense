#include "base_tower.h"
#include "raylib.h"
#include <vector>
#include "bullet.h"
#include "raymath.h"
#include<string>
#include "mouseStatus.h"

void base_tower::Draw()
{
    DrawTexturePro(texture,collisionRect,{position.x+32, position.y+32,texture.width*scale,texture.height*scale},{32,32},rotation,WHITE);
    if (isClicked)
    {
        DrawCircleLines(position.x + 32, position.y + 32, range, YELLOW);
        string tower_range {"Range: "};
        tower_range.append(to_string(range),0,5);
        DrawText(tower_range.c_str(),770,588,40,BLACK);
        string tower_power {"Power: "};
        tower_power.append(to_string(power),0,5);
        DrawText(tower_power.c_str(),770,652,40,BLACK);
        upgrade_button.Draw();

    }
    
    for (auto bullet : bullets)
    {

        bullet->Draw();
    }
}
void base_tower::Update(float deltaTime, float window_Width, float window_Height,int &funds,mouseStatus status)
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&& status == mouseStatus::IDLE)
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
            Vector2 bulletDirection = Vector2Normalize(Vector2Subtract({target->getPosition().x + 16, target->getPosition().y+16}, position));
            bullets.push_back(new Bullet({position.x, position.y}, bulletDirection, target));
            bulletTimer = 0.0f;
        }
        rotation= Vector2Angle(position,target->getPosition())+180;
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
                funds+=bullet->GetTarget()->getReward();

            }
        }
        if (bullet->GetPosition().x < 0 || bullet->GetPosition().y < 0 || bullet->GetPosition().y > window_Height || bullet->GetPosition().x > window_Width-4*64)
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
    collisionRect={0,0,static_cast<float>(tex.width),static_cast<float>(tex.height)};
}
base_tower::base_tower(Vector2 pos) : texture{LoadTexture("textures/tower.png")}, position{pos}
{
    range = 128;
    power = 1;
    collisionRect={0,0,static_cast<float>(texture.width),static_cast<float>(texture.height)};
}
void base_tower::setTarget(Enemy *enemy)
{
    target = enemy;
}

void base_tower::setHasTarget(bool target)
{
    hasTarget = target;
}