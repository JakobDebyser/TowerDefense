#include "enemy.h"
#include "raymath.h"

Enemy:: Enemy():
    position{64, -64},
    speed{100},
    health{1}
    {
        collisionRect={static_cast<float>(texture.width),static_cast<float>(texture.height)};
}

void Enemy::Update(float deltaTime){
    CalculateDirection(waypointIndex);
    direction = Vector2Scale(direction, speed * deltaTime);
    position = Vector2Add(position, direction);

    if(Vector2Distance(position, waypoints[waypointIndex]) < 2){
        waypointIndex++;
        if(waypointIndex >= 8){

            //TODO enemy reach base
            speed = 0;
        }
    }
}

void Enemy::CalculateDirection(int index){
    direction = Vector2Subtract(waypoints[index], position);
    direction = Vector2Normalize(direction);
}

void Enemy::Draw() {
    //todo texture width and height replace
    DrawRectangle(position.x+20, position.y+20, 25, 25, RED);
    
}