#include "upgrade_button.h"
Upgrade_Button::Upgrade_Button() : position{770, 728},
                                   collisionRect{position.x, position.y, 50, 250} {};

void Upgrade_Button::Draw()
{
        DrawRectangle(768, 708, 250, 32, PURPLE);
}
void Upgrade_Button::update()
{
        
}