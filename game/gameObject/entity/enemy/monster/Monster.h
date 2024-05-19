#include "../Enemy.h"
#ifndef SDL_GAME_MONSTER_H
#define SDL_GAME_MONSTER_H

struct MonsterConfig{
    int min_X;
    int max_X;
    int moveVector;
    int frame=0;
};

class Monster: public Entity {
public:
    Monster(EntityCreator entityCreator,MonsterConfig monsterConfig): Entity(entityCreator),monsterConfig(monsterConfig){}
    void move();
    void move(int x);
    void changeDirection();
    void addFrame(){monsterConfig.frame++;}
    void addFrame(int frame){monsterConfig.frame=frame;}
    MonsterConfig getMonsterConfig(){return monsterConfig;}
    void setAnimation(SDL_Renderer* renderer);
    void update(SDL_Renderer* renderer);
    SDL_Texture* texture = nullptr;
    void load_Texture(SDL_Renderer *render);
private:
    MonsterConfig monsterConfig;
    int textureWidth;
    int textureHeight;
    int frameWidth;
    int frameHeight;
    int frameCountX;
    int frameCountY;
    int frame=0;
};


#endif //SDL_GAME_MONSTER_H
