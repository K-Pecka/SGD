//
// Created by Kacper on 12.05.2024.
//

#ifndef SDL_GAME_PLAYER_H
#define SDL_GAME_PLAYER_H

#include <SDL_rect.h>
#include "Game.h"

enum class Direction{
    LEFT,RIGHT,UP,DOWN
};
struct Object{
    int x = 0;
    int y = 0;
    int w = 50;
    int h = 50;
};
struct Hero{
    Object player;
    int speedPlayer = 5;
};

class Player : public GameObject {
public:
    explicit Player(Hero hero) : GameObject( (Object) hero.player), speed(hero.speedPlayer) {};

    void move(int dx, int dy,Direction direction);
    SDL_Rect getObject() {return {x, y, height, width};}
    [[nodiscard]] Direction getDirection() const { return direction; }
    void setDirection(Direction directionPlayer) { this->direction=directionPlayer; }

    [[nodiscard]] int getSpeed() const {return speed;}

private:
    Direction direction;
    int speed;
};


#endif //SDL_GAME_PLAYER_H
