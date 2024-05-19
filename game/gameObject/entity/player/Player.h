#ifndef SDL_GAME_PLAYER_H
#define SDL_GAME_PLAYER_H

#include <SDL_image.h>
#include <SDL_rect.h>
#include <iostream>
#include "../Entity.h"

class Player : public Entity {
public:
    explicit Player(EntityCreator hero) :   Entity(hero) {};

    void toString() const override;
    void update(SDL_Renderer* render);
    void setAnimation(SDL_Renderer* renderer);
    SDL_Texture* texture = nullptr;
    void load_Texture(SDL_Renderer *render);
    void addFrame(){frame++;}
private:
    int textureWidth;
    int textureHeight;
    int frameWidth;
    int frameHeight;
    int frameCountX;
    int frameCountY;
    int frame=0;
};


#endif //SDL_GAME_PLAYER_H
