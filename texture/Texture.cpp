#include "Texture.h"
char * Texture::getTextureTypeSrc(TextureType type)
{
    switch(type){
        case TextureType::GRASS:
            return "../asset/grass.png";
        case TextureType::GRASS_SURFACE:
            return "../asset/grass_surface.bmp";
        case TextureType::FILLER:
            return "../asset/cobelstone.bmp";
        case TextureType::METAL:
            return "../asset/cobelstone.bmp";
        case TextureType::HERO:
            return "../asset/hero.png";
        case TextureType::MONSTER:
            return "../asset/hero.png";
        case TextureType::NULL_PTR:
        default:
            return "../asset/cobelstone.bmp";
    }
}
char * Texture::getTexture() const {
    return getTextureTypeSrc(getTextureTypeT());
}
char * Texture::getTexture(TextureType textureType) {
    return getTextureTypeSrc(textureType);
}