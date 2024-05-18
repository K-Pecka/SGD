#include "../Enemy.h"
#ifndef SDL_GAME_MONSTER_H
#define SDL_GAME_MONSTER_H

struct MonsterConfig{
    int min_X;
    int max_X;
    int moveVector;
};

class Monster: public Entity {
public:
    Monster(EntityCreator entityCreator,MonsterConfig monsterConfig): Entity(entityCreator),monsterConfig(monsterConfig){}
    void move();
    void move(int x);
    void changeDirection();
    MonsterConfig getMonsterConfig(){return monsterConfig;}
private:
    MonsterConfig monsterConfig;

};


#endif //SDL_GAME_MONSTER_H
