#include "Platform.h"
RGBa Platform::getPlatformColor(PlatformType platformType) {
    switch(platformType){
        case PlatformType::GRASS:
            return {0,250,0,0};
        case PlatformType::FILLER:
            return {30,30,30,0};
        case PlatformType::METAL:
            return {123,123,213,0};
        case PlatformType::NULL_PTR:
        default:
            return {0,0,0,0};
    }

}
char * Platform::getPlatformTexture(PlatformType platformType) {
    switch(platformType){
        case PlatformType::GRASS:
            return "../asset/grass.bmp";
        case PlatformType::FILLER:
            return "../asset/cobelstone.bmp";
        case PlatformType::METAL:
            return "../asset/cobelstone.bmp";
        case PlatformType::NULL_PTR:
        default:
            return "../asset/cobelstone.bmp";
    }
}
void Platform::repeatTexture(SDL_Renderer* renderer) {
    int texW = 0;
    int texH = 0;

    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    int i=0;
    for (int yy= y; yy < height+y; yy += texH) {
        for (int xx = x; xx < width+x; xx += texW) {
            SDL_Rect dstRect = { xx, yy, texW, texH };
            SDL_RenderCopy(renderer, texture, NULL, &dstRect);
        }
        i++;
    }
}
SDL_Texture* loadTexture(const char* file, SDL_Renderer* renderer) {
    SDL_Surface* tempSurface = SDL_LoadBMP(file);
    if (tempSurface == nullptr) {
        std::cerr << "Failed to load BMP: " << SDL_GetError() << std::endl;
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return texture;
}
void Platform::setTexture(SDL_Renderer* renderer)
{
    texture = loadTexture(getPlatformTexture(platformType), renderer);
    if (texture == nullptr) {
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }
    repeatTexture(renderer);
}
