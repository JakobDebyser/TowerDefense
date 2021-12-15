#include"mouseObject.h"
#include"math.h"

MouseObject::MouseObject() {
    status = status.IDLE;
}

void MouseObject::Update(float deltaTime){
    switch (status.value())
    {
    case 0: //BUILDING BASIC TOWER
        if(IsMouseButtonPressed(0)){

        }
        break;
    
    default:
        break;
    }

    if(IsMouseButtonPressed(1)){
        status = status.IDLE;
    }
}

void MouseObject::Draw(){
    switch (status.value())
    {
    case 0: //BUILDING BASIC TOWER
        DrawRectangle(floor(GetMouseX()/64)*64 + 20, floor(GetMouseY()/64)*64 + 20, 32, 32, WHITE);
        break;
    
    default:
        break;
    }
}

void MouseObject::setStatus(mouseStatus stat){
    status = stat;
}