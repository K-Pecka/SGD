#include "Monster.h"
void Monster::move() {
    setX(getX()+speed.vx * monsterConfig.moveVector);
}
void Monster::move(int x) {
    setX(x);
}
void Monster::changeDirection() {
    monsterConfig.moveVector *= -1;
}