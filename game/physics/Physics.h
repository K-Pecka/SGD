//
// Created by Kacper on 15.05.2024.
//

#ifndef SDL_GAME_PHYSICS_H
#define SDL_GAME_PHYSICS_H

class Physics {
public:
    Physics() =default;
    static int getGravitation()  {return gravity;}
private:
    static const int gravity=9;
};


#endif //SDL_GAME_PHYSICS_H
