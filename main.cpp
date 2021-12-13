#include"raylib.h"

int main(){
    InitWindow(1024,768,"TowerDefense");
   Texture2D WorldMap= LoadTexture("textures/testmap.png");


    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
        DrawTextureEx(WorldMap,{0,0},0.f,2,WHITE);



        EndDrawing();
    }

    return 0;
}
