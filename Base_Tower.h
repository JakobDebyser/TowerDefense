#ifndef _BASE_TOWER_H_
#define _BASE_TOWER_H_
#include "raylib.h"
#include "enemy.h"
#include <vector>
#include "bullet.h"
#include"Upgrade_Button.h"
#include "mouseStatus.h"
class base_tower
{
public:
    int getRange() { return range; }
    int getPower() { return power; }
    Vector2 getPosition() { return position; }
    Enemy* getTarget() { return target; }
    bool getHasTarget(){return hasTarget;}
    void setTarget(Enemy* enemy);
    void setHasTarget(bool target);
    bool getIsClicked() { return isClicked; }
    base_tower(Vector2 position);
    base_tower(Texture2D texture, Vector2 position);
    void Update(float deltaTime,float window_Width,float window_Height, int &funds,mouseStatus status);
    void Draw();
    Upgrade_Button getUpgradeButton() { return upgrade_button; }
    int getCost() { return cost; }
    protected:
    Rectangle collisionRect{};
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
    Upgrade_Button upgrade_button{LoadTexture("textures/upgradeButton.png"),{770,708}};
    int cost{20};
    int towerLevel{1};
    
};

#endif // _BASE_TOWER_H_
