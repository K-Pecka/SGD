

#include "Player.h"
void Player::move(int dx, int dy,Direction directionPlayer) {
    y+=dy;
    x+=dx;
    direction = directionPlayer;
}

