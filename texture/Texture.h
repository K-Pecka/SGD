
#ifndef SDL_GAME_TEXTURE_H
#define SDL_GAME_TEXTURE_H

#include <utility>
#include <vector>
#include <SDL.h>
enum class TextureType{
    FILLER,GRASS,METAL,NULL_PTR
};
struct TextureConfig{
    int offsetX = 0 ;
    int offsetY = 0 ;
    TextureType textureType = TextureType::NULL_PTR;
    SDL_Texture* sdl_texture= nullptr;
};

class Texture {
public:
    explicit Texture(TextureConfig layerTextures):layerTextures(layerTextures){}

    char * getTexture();
    int getOffsetX()const{return layerTextures.offsetX;};
    int getOffsetY()const{return layerTextures.offsetY;};
    void setSDLTexture(SDL_Texture* texture) { layerTextures.sdl_texture = texture; }
    TextureConfig layerTextures;
private:


    TextureType getTextureType() const{return layerTextures.textureType;}
};


#endif //SDL_GAME_TEXTURE_H
