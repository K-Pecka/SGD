
#ifndef SDL_GAME_TEXTURE_H
#define SDL_GAME_TEXTURE_H

#include <utility>
#include <vector>
#include <SDL.h>
enum class TextureType{
    FILLER,GRASS,METAL,GRASS_SURFACE,HERO,NULL_PTR
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

    char * getTexture() const;
    static char * getTextureTypeSrc(TextureType);
    static char * getTexture(TextureType);
    int getOffsetX()const{return layerTextures.offsetX;};
    int getOffsetY()const{return layerTextures.offsetY;};
    void setSDLTexture(SDL_Texture* texture) { layerTextures.sdl_texture = texture; }
    TextureConfig layerTextures;
    TextureType getTextureTypeT() const{return layerTextures.textureType;}
private:
};


#endif //SDL_GAME_TEXTURE_H
