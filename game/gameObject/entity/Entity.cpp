#include "Entity.h"
void Entity::move(int dx, int dy,Direction directionPlayer) {
    setX(getX() + dx);
    setY(getY() + dy);
    direction = directionPlayer;
}
void Entity::move(int dx, int dy) {
    setX(dx);
    setY(dy);
}
void Entity::selectDirectionCollision(int dx,int dy){

    switch (getDirection()) {
        case Direction::LEFT:
            move(dx , dy, Direction::RIGHT);
            break;
        case Direction::RIGHT:
            move(dx, dy, Direction::LEFT);
            break;
        case Direction::UP:
            move(dx, dy, Direction::DOWN);
            break;
        case Direction::DOWN:
            move(dx, dy, Direction::UP);
            break;

    }
}