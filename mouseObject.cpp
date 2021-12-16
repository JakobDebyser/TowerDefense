#include "mouseObject.h"
#include "math.h"

MouseObject::MouseObject()
{
    status = status.IDLE;
}

void MouseObject::Update(float deltaTime, Tile tiles[12][12],vector<base_tower *>& towers,int &funds)
{
    switch (status.value())
    {
    case 0: // BUILDING BASIC TOWER
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&& getMouseTile().x<12&&funds>0)
        {
            string grass = "grass";
            if (tiles[(int)getMouseTile().x][(int)getMouseTile().y].getName() == grass)
            {
                // build towerTexture
                towers.push_back(new base_tower({getMouseTile().x*64, getMouseTile().y*64}));
                tiles[(int)getMouseTile().x][(int)getMouseTile().y].setName("tower");
                funds-=20;//tower cost
            }
        }
        break;

    default:

        break;
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
    {
        status = status.IDLE;
    }
}

void MouseObject::Draw()
{
    switch (status.value())
    {
    case 0: // BUILDING BASIC TOWER
        DrawRectangle(floor(GetMouseX() / 64) * 64 + 20, floor(GetMouseY() / 64) * 64 + 20, 32, 32, WHITE);
        break;

    default:
        break;
    }
}

void MouseObject::setStatus(mouseStatus stat)
{
    status = stat;
}

Vector2 MouseObject::getMouseTile()
{
    return {static_cast<float>(floor(GetMouseX() / 64)), static_cast<float>(floor(GetMouseY() / 64))};
}