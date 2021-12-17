#ifndef _UPGRADE_BUTTON_H_
#define _UPGRADE_BUTTON_H_

#include "button.h"
#include "mouseStatus.h"
using namespace std;

class Upgrade_Button : public Button
{
public:
    Upgrade_Button(Texture2D tex, Vector2 pos);
    void setIsVisible(bool visible);
    bool isVisible() { return visible; }
    void update(float deltaTime);

protected:
    Texture2D texture{LoadTexture("textures/upgradeButton.png")};
    Vector2 position{};
    Rectangle collisionRect{};
    mouseStatus status{};
    bool visible{};

private:
};

#endif