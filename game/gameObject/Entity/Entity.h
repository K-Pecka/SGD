#include "../GameObject.h"
#ifndef SDL_GAME_ENTITY_H
#define SDL_GAME_ENTITY_H

struct SpeedEntity{
    int vx;
    int vy;
};
struct EntityCreator{
    Object player;
    RGBa color;
    SpeedEntity speedPlayer = {0,0};
};

class Entity: public GameObject{
public:
    explicit Entity(EntityCreator entity) : GameObject((Object) entity.player,entity.color), speed(entity.speedPlayer) {};

    void move(int dx, int dy,Direction direction);
    void move(int dx, int dy);
    [[nodiscard]] Direction getDirection() const { return direction; }
    [[maybe_unused]] void setDirection(Direction directionPlayer) { this->direction=directionPlayer; }
    [[nodiscard]] SpeedEntity getSpeed() const {return speed;}
    void selectDirectionCollision(int,int);
    void collision() {speed.vy=0;}
    void fall() {speed.vy=1;}

protected:
    Direction direction=Direction::NULL_PTR;
    SpeedEntity speed;
};


#endif //SDL_GAME_ENTITY_H
