#ifndef MOUSEOBJECT
#define MOUSEOBJECT
#include"mouseStatus.h"
#include"raylib.h"

class MouseObject {
    public:
        void setStatus(mouseStatus stat);
        mouseStatus getStatus(){return status;};
        void Update(float deltaTime);
        void Draw();
        MouseObject();
    private:
        mouseStatus status{};
};

#endif