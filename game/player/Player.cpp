#include "Player.h"
void Player::move(float dx, float dy,Direction directionPlayer) {
    setX(getX() + dx);
    setY(getY() + dy);
    direction = directionPlayer;
}
void Player::move(float dx, float dy) {
    setX(dx);
    setY(dy);
}
void Player::toString() const {

    std::cout<<"Player info: "<<std::endl;
    GameObject::toString();
    std::cout<<"{ speed: "<<getSpeed()<<" }"<<std::endl;
}
void Player::selectDirectionCollision(float dx,float dy){

    switch (getDirection()) {
        case Direction::LEFT:
            move(-dx + getSpeed(), -dy, Direction::RIGHT);
            break;
        case Direction::RIGHT:
            move(-dx - getSpeed(), -dy, Direction::LEFT);
            break;
        case Direction::UP:
            move(-dx, -dy + getSpeed(), Direction::DOWN);
            break;
        case Direction::DOWN:
            move(-dx, -dy - getSpeed(), Direction::UP);
            break;

    }
}

void Player::update(){
//    if(setting.gravityable)
//        game.setGravitation();
}