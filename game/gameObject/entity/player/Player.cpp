#include "Player.h"
#include "../../../physics/Physics.h"

void Player::toString() const {

    std::cout<<"Player info: "<<std::endl;
    GameObject::toString();
}

void Player::update(){
    if(getSpeed().gravity)
    {
        y += speed.vy+Physics::getGravitation();
        setSpeedY(speed.vy+Physics::getGravitation());
    }
}