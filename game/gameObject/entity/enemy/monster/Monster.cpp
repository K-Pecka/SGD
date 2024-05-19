#include "Monster.h"
void Monster::move() {
    setX(getX()+speed.vx * monsterConfig.moveVector);
}
void Monster::move(int x) {
    setX(x);
}
void Monster::changeDirection() {
    monsterConfig.moveVector *= -1;
    if(getDirection() == Direction::RIGHT)setDirection(Direction::LEFT);
    else setDirection(Direction::RIGHT);
}


void Monster::load_Texture(SDL_Renderer* renderer) {

    SDL_Surface* tempSurface = IMG_Load(Texture::getTextureTypeSrc(TextureType::MONSTER));
    if (tempSurface == nullptr) {
        std::cerr << "Failed to load IMAGE: " << SDL_GetError() << std::endl;
    }

    texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_QueryTexture(texture,NULL,NULL,&textureWidth,&textureHeight);
    frameWidth = textureWidth / 4;
    frameHeight = textureHeight / 4;
    SDL_FreeSurface(tempSurface);
}
void Monster::update(SDL_Renderer* render){
    if(texture == nullptr) {
        load_Texture(render);
    }
    setAnimation(render);
}

void Monster::setAnimation(SDL_Renderer *renderer) {
    SDL_Rect playerAnimation={0,frameHeight*(int)getDirection(),frameWidth,frameHeight};
    SDL_Rect player={getX(),getY(),getWidth(),getHeight()};
    if(frame == 4)
    {
        frame=0;
        playerAnimation.x += frameWidth;
        if(playerAnimation.x >= textureWidth)
        {
            playerAnimation.x=0;
        }
    }
    frame++;
    SDL_RenderCopy(renderer,texture,&playerAnimation,&player);
}