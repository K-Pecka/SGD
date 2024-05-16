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
    RGBa color;
    int speedPlayer = 5;
};

class Player : public GameObject {
public:
    Player(Hero hero,RGBa rgba) : GameObject((Object) hero.player,rgba), speed(hero.speedPlayer) {};

    void move(float dx, float dy,Direction direction);
    void move(float dx, float dy);
    [[nodiscard]] Direction getDirection() const { return direction; }

    [[maybe_unused]] void setDirection(Direction directionPlayer) { this->direction=directionPlayer; }
    void toString() const override;
    [[nodiscard]] int getSpeed() const {return speed;}
    void update();
    void selectDirectionCollision(float,float);
protected:
    Direction direction;
    int speed;
};


#endif //SDL_GAME_PLAYER_H
