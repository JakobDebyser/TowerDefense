#ifndef _BASE_TOWER_H_
#define _BASE_TOWER_H_
#include "raylib.h"
#include "enemy.h"
#include <vector>
#include "bullet.h"
using namespace std;
class base_tower
{
public:
    int getRange() { return range; }
    int getPower() { return power; }
    Vector2 getPosition() { return position; }
    Enemy* getTarget() { return target; }
    void setTarget(Enemy* enemy);
    void setHasTarget(bool target);
    bool getIsClicked() { return isClicked; }
    base_tower(Texture2D texture, Vector2 position);
    void Update(float deltaTime);
    void Draw();

private:
    Texture2D texture{};
    int range{};
    int power{};
    Vector2 position{};
    Enemy* target{};
    bool isClicked{};
    float rotation{0};
    float scale{2};
    vector<Bullet*> bullets;
    bool hasTarget{};
    float bulletTimer{0.0f};
};

#endif // _BASE_TOWER_H_
