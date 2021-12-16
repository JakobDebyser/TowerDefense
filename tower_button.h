#ifndef _TOWER_BUTTON
#define _TOWER_BUTTON

#include "button.h"
#include "mouseStatus.h"
#include"Base_Tower.h"
using namespace std;

class TowerButton : public Button
{
public:
TowerButton(Texture2D tex, Vector2 pos);
int getTowerCost()const { return tower_cost;}
protected:
    Texture2D texture;
    Vector2 position;
    Rectangle collisionRect;
    mouseStatus status{};
    int tower_cost{ 20};
private:
};

#endif