#include "enemy.h"
#include "raymath.h"
#include <math.h>

Enemy::Enemy(int difficultyLevel) : position{64, -64},
                 speed{100},
                 health{difficultyLevel},
                 maxHealth{difficultyLevel}

{
    // collisionRect={static_cast<float>(texture.width),static_cast<float>(texture.height)};
    collisionRect = {position.x, position.y, 30.f, 30.f};
    if (difficultyLevel%5==0){
        speed+=25*difficultyLevel/5;
    }
    if (difficultyLevel%2==0){
            reward+=5*difficultyLevel/2;
    }
    
}
Enemy::Enemy(Texture2D tex,int difficultyLevel) :texture(tex), position{64, -64},
                 speed{100},
                 health{difficultyLevel},
                 maxHealth{difficultyLevel}

{
    // collisionRect={static_cast<float>(texture.width),static_cast<float>(texture.height)};
    collisionRect = {position.x, position.y, 30.f, 30.f};
    if (difficultyLevel%5==0){
        speed+=25*difficultyLevel/5;
    }
    if (difficultyLevel%2==0){
            reward+=5*difficultyLevel/2;
    }
    
}


void Enemy::Update(float deltaTime, int &lives)
{
    
    collisionRect = {position.x, position.y, 30.f, 30.f};

    CalculateDirection(waypointIndex);
    direction = Vector2Scale(direction, speed * deltaTime);
    position = Vector2Add(position, direction);

    if (Vector2Distance(position, waypoints[waypointIndex]) < 2)
    {
        waypointIndex++;
        if (waypointIndex >= 8)
        {

            // TODO enemy reach base
            speed = 0;
            lives--;
        }
    }
}

void Enemy::CalculateDirection(int index)
{
    direction = Vector2Subtract(waypoints[index], position);
    direction = Vector2Normalize(direction);
    if(direction.x >= 0.9f && direction.y<=0.1f){ //RECHTS
        rotation=270;
    } else if(direction.x <= -0.9f && direction.y<=0.1f){ //LINKS
        rotation=90;
    } else if(direction.y >= 0.9f && direction.x<=0.1f){ //DOWN
        rotation=0;
    } else if(direction.y <= -0.9f && direction.y<=0.1f){ //UP
        rotation=180;
    }
}

void Enemy::Draw()
{
    // todo texture width and height replace
    if (waypointIndex < 8)
    {
        DrawTexturePro(texture, {0, 0, 32, 32}, {position.x+32, position.y+32, static_cast<float>(texture.width*2),static_cast<float>(texture.height*2)}, {32, 32}, rotation, WHITE);  
        //DrawRectangle(position.x +18, position.y+18, 30, 30, RED);

        //healtbar
        DrawRectangle(position.x + 18, position.y + 5, 30, 5, RED);
        DrawRectangle(position.x + 18, position.y + 5, health * 30 / maxHealth, 5, GREEN);
    }
}
void Enemy::takeDamage(int damage)
{

    health -= damage;
    if (health <= 0)
    {
        Alive = false;
    }
}