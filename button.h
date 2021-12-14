#ifndef _BUTTON_H_
#define _BUTTON_H_
#include "raylib.h"

class Button
{
public:
    Button(Texture2D texture, Vector2 position);
    bool isClicked();
    void Draw();
    int getScale() { return scale; }

protected:
    Texture2D texture;
    Vector2 position;
    int scale{2};
    Rectangle collisionRect;
};

#endif