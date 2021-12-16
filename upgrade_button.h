#ifndef _UPGRADE_BUTTON_H_
#define _UPGRADE_BUTTON_H_

#include "button.h"
#include "mouseStatus.h"
using namespace std;

class Upgrade_Button : public Button
{
public:
    Upgrade_Button();
    void setIsVisible(bool visible);
    bool isVisible() { return visible; }
    void Draw();
    void update();

protected:
    Texture2D texture;
    Vector2 position;
    Rectangle collisionRect;
    mouseStatus status{};
    bool visible{};

private:
};

#endif