#include "../GameObject.h"
#ifndef SDL_GAME_WALL_H
#define SDL_GAME_WALL_H


class Wall:public GameObject {
public:
    Wall(const Object& object, const RGBa& rgba) : GameObject(object, rgba) {}
};


#endif //SDL_GAME_WALL_H
