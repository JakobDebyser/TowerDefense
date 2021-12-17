#include"boss_enemy.h"

void bossEnemy::Update(float deltaTime,int &lives){

    Enemy::Update(deltaTime,lives);
}
bossEnemy::bossEnemy(Texture2D texture, int difficulty):Enemy(texture,difficulty)
{
   Enemy::maxHealth=5*difficulty;
    Enemy::health=5*difficulty;
    
}
void bossEnemy::Draw(){ 
 if (waypointIndex < 8)
    {
        DrawTexturePro(texture, {0, 0, 32, 64}, {Enemy::position.x+32, Enemy::position.y+32, static_cast<float>(texture.width*2),static_cast<float>(texture.height*2)}, {32, 96}, Enemy::rotation, WHITE);  
        //DrawRectangle(position.x +18, position.y+18, 30, 30, RED);

        //healtbar
        DrawRectangle(Enemy::position.x + 18, Enemy::position.y + 5, 30, 5, RED);
        DrawRectangle(Enemy::position.x + 18, Enemy::position.y + 5, Enemy::health * 30 / Enemy::maxHealth, 5, GREEN);
    }

}