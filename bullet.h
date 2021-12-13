#ifndef _BULLET_
#define _BULLET_

#include "raylib.h"

class Bullet {
    public:
        Bullet(Vector2 position, Vector2 direction);
        void Update(float deltaTime);
        void Draw();
    private:
        Vector2 position{};
        Vector2 direction {};
        float speed;
};

#endif