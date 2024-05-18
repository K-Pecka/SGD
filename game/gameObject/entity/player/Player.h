//
// Created by Kacper on 12.05.2024.
//

#ifndef SDL_GAME_PLAYER_H
#define SDL_GAME_PLAYER_H

#include <SDL_rect.h>
#include <iostream>
#include "../Entity.h"


class Player : public Entity {
public:
    explicit Player(EntityCreator hero) :   Entity(hero) {};

    void toString() const override;
    void update();
};


#endif //SDL_GAME_PLAYER_H
