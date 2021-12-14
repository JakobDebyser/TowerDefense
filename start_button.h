#ifndef START_BUTTON_H__
#define START_BUTTON_H__
#include "button.h"
class start_button : public Button
{
public:
    start_button(Texture2D texture, Vector2 position);

protected:
    Texture2D texture;
    Vector2 position;
    Rectangle collisionRect;
};
#endif