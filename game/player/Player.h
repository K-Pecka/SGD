//
// Created by Kacper on 12.05.2024.
//

#ifndef SDL_GAME_PLAYER_H
#define SDL_GAME_PLAYER_H

#include <SDL_rect.h>
#include <iostream>
#include "../gameObject/GameObject.h"

struct Hero{
    Object player;
    int speedPlayer = 5;
};

class Player : public GameObject {
public:
    explicit Player(Hero hero) : GameObject((Object) hero.player), speed(hero.speedPlayer) {};

    void move(int dx, int dy,Direction direction);
    void move(int dx, int dy);
    [[nodiscard]] Direction getDirection() const { return direction; }

    [[maybe_unused]] void setDirection(Direction directionPlayer) { this->direction=directionPlayer; }
    void toString() const override;
    [[nodiscard]] int getSpeed() const {return speed;}
    void update();
    void selectDirectionCollision(int,int);
protected:
    Direction direction;
    int speed;
};


#endif //SDL_GAME_PLAYER_H
