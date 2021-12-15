#include "Tile.h"

void Tile::Draw(){
    if(name=="grass"){
        DrawRectangle(position.x,position.y,63,63,GREEN);
    }else if(name=="road"){
        DrawRectangle(position.x,position.y,63,63,YELLOW);
    }else if(name=="base"){
        DrawRectangle(position.x,position.y,63,63,BLACK);
    }
    
}
Tile::Tile(Vector2 pos,string tile_name):position{pos},name{tile_name} 
{

}