#include "Platform.h"

#include <utility>

RGBa Platform::getPlatformColor(PlatformType platformType) {
    switch(platformType) {
        case PlatformType::GRASS:
            return {0, 250, 0, 255};
        case PlatformType::FILLER:
            return {30, 30, 30, 255};
        case PlatformType::METAL:
            return {123, 123, 213, 255};
        case PlatformType::NULL_PTR:
        default:
            return {0, 0, 0, 255};
    }
}

void Platform::addLayerTexture(Texture texture) {
    textures.push_back(texture);
}
SDL_Texture* loadTexture(const char* file, SDL_Renderer* renderer) {
    SDL_Surface* tempSurface = IMG_Load(file);
    if (tempSurface == nullptr) {
        std::cerr << "Failed to load BMP: " << SDL_GetError() << std::endl;
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return texture;
}
void Platform::setTexture(SDL_Renderer* renderer) {
    for (auto& textureObj : textures) {
        textureObj.setSDLTexture(loadTexture(textureObj.getTexture(), renderer));
        if (textureObj.layerTextures.sdl_texture == nullptr) {
            std::cerr << "Failed loadTexture: " << SDL_GetError() << std::endl;
            SDL_DestroyRenderer(renderer);
            SDL_Quit();
            return;
        }
    }
    for (const auto& layer : textures) {
        if (layer.layerTextures.sdl_texture != nullptr) {
            int texW = 0;
            int texH = 0;

            SDL_QueryTexture(layer.layerTextures.sdl_texture, NULL, NULL, &texW, &texH);
            if(layer.layerTextures.textureType == TextureType::GRASS)
            {
                for (int xx = x; xx < x + width; xx += texW) {

                    SDL_Rect dstRect;
                    if(xx%3 == 0)
                    {
                        dstRect = {xx+layer.getOffsetX(), y+layer.getOffsetY(), texW, texH};
                    }
                    SDL_RenderCopy(renderer, layer.layerTextures.sdl_texture, NULL, &dstRect);
                }
            }
            else
            {
                for (int yy = y; yy < y + height; yy += texH) {
                    for (int xx = x; xx < x + width; xx += texW) {
                        SDL_Rect dstRect = {xx+layer.getOffsetX(), yy+layer.getOffsetY(), texW, texH};
                        SDL_RenderCopy(renderer, layer.layerTextures.sdl_texture, NULL, &dstRect);
                    }
                }
            }

        }
    }
}
void Platform::renderTexture(SDL_Renderer* renderer) const {}