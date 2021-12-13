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
}
void base_tower::Update(float deltaTime)
{
    if (target)
    {
        Vector2 direction = Vector2Normalize(Vector2Subtract(target->getPosition(), position));
       // bullets->push_back(new Bullet(position, direction));
    }
}

base_tower::base_tower(Texture2D tex, Vector2 pos)
{
    texture = tex;
    position = pos;
    range = 128;
}
void base_tower::setTarget(Enemy enemy)
{
    *target = enemy;
   
}