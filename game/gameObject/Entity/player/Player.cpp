#include "Player.h"
#include "../../../physics/Physics.h"

void Player::toString() const {

    std::cout<<"Player info: "<<std::endl;
    GameObject::toString();
}

void Player::update(){
    y += Physics::getGravitation()*speed.vy;
}