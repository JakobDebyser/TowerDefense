#ifndef _MOUSEOBJECT_H_
#define _MOUSEOBJECT_H_
#include"mouseStatus.h"
#include"raylib.h"
#include"Tile.h"
#include"Base_Tower.h"
#include<vector>

using std::vector;
class MouseObject {
    public:
        void setStatus(mouseStatus stat);
        mouseStatus getStatus(){return status;};
        void Update(float deltaTime,Tile tiles[12][12],vector<base_tower *>&towers,int &funds);
        void Draw();
        MouseObject();
        Vector2 getMouseTile();
    
    private:
        mouseStatus status{};
};

#endif