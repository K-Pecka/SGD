#include "Player.h"
#include "../../../physics/Physics.h"

void Player::toString() const {

    std::cout<<"Player info: "<<std::endl;
    GameObject::toString();
}
void Player::load_Texture(SDL_Renderer* renderer) {

    SDL_Surface* tempSurface = IMG_Load(Texture::getTextureTypeSrc(TextureType::HERO));
    if (tempSurface == nullptr) {
        std::cerr << "Failed to load IMAGE: " << SDL_GetError() << std::endl;
    }

    texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_QueryTexture(texture,NULL,NULL,&textureWidth,&textureHeight);
    frameWidth = textureWidth / 4;
    frameHeight = textureHeight / 4;
    SDL_FreeSurface(tempSurface);
}
void Player::update(SDL_Renderer* render){
    if(getSpeed().gravity)
    {
        y += speed.vy+Physics::getGravitation();
        setSpeedY(speed.vy+Physics::getGravitation());
    }
    if(texture == nullptr) {
        load_Texture(render);
    }

    setAnimation(render);
}

void Player::setAnimation(SDL_Renderer *renderer) {
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
    std::cout<<frame<<std::endl;
    SDL_RenderCopy(renderer,texture,&playerAnimation,&player);
}
