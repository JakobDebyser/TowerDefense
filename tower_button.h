#ifndef _TOWER_BUTTON
#define _TOWER_BUTTON

#include "button.h"
#include "mouseStatus.h"
using namespace std;

class TowerButton : public Button
{
public:
TowerButton(Texture2D tex, Vector2 pos);
protected:
    Texture2D texture;
    Vector2 position;
    Rectangle collisionRect;
    mouseStatus status{};

private:
};

#endif