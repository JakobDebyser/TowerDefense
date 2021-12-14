#include "button.h"

void Button::Draw()
{
    DrawTextureEx(texture, position, 0.f, getScale(), WHITE);
}
Button::Button(Texture2D tex, Vector2 pos)
    : texture{tex},
      position{pos}, collisionRect{
                         position.x,
                         position.y,
                         static_cast<float>(tex.width),
                         static_cast<float>(tex.height)}
{
}
bool Button::isClicked()
{
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(GetMousePosition(), collisionRect))
        {
            return true;
        }
    }
    return false;
}