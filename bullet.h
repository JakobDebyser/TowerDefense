#ifndef _BULLET_
#define _BULLET_

#include "raylib.h"
#include "enemy.h"

class Bullet {
    public:
        Bullet(Vector2 position, Vector2 direction,Enemy *target);
        void Update(float deltaTime);
        void Draw();
        Vector2 GetPosition(){return position;};
        Enemy *GetTarget(){return target;}
        
    private:
        Vector2 position{};
        Vector2 direction {};
        float speed;
        Enemy *target;
};

#endif