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
    if(dx==0)
        move(dx , dy, Direction::DOWN);
    if(getX()<dx+getX())
        move(dx , dy, Direction::RIGHT);
    else
        move(dx , dy, Direction::LEFT);
}