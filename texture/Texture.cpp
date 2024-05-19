#include "Texture.h"
char * Texture::getTexture() {
    switch(layerTextures.textureType){
        case TextureType::GRASS:
            return "../asset/grass.bmp";
        case TextureType::FILLER:
            return "../asset/cobelstone.bmp";
        case TextureType::METAL:
            return "../asset/cobelstone.bmp";
        case TextureType::NULL_PTR:
        default:
            return "../asset/cobelstone.bmp";
    }
}