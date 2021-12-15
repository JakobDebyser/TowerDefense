#ifndef TILE
#define TILE
#include "raylib.h"
#include <string>
using namespace std;
class Tile
{
public:
    Vector2 getPosition() const { return position; }
    string getName() const { return name; }
    void setName(string tile_name){name=tile_name; }
    void Draw();
    Tile(Vector2 position={}, string name="");

private:
    Vector2 position;
    string name;
};

#endif