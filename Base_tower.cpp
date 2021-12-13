#include "base_tower.h"
#include "raylib.h"

void base_tower::Draw(){
    DrawTextureEx(texture,position,rotation,scale,WHITE);

}
void base_tower::Update(float deltaTime){ 


}

base_tower:: base_tower(Texture2D tex, Vector2 pos){
    texture = tex;
    position = pos;

}