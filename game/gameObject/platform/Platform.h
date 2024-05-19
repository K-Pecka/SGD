#ifndef SDL_GAME_PLATFORM_H
#define SDL_GAME_PLATFORM_H
#include <random>
#include <SDL_image.h>
#include "../../../texture/Texture.h"
#include "../GameObject.h"
enum class PlatformType {
    FILLER, GRASS, METAL,GOAL, NULL_PTR
};
struct ObjectConfig{
    Object size = {50,10};
    RGBa color = {23,23,23};
};

struct PlatformConfig{
    ObjectConfig object;
    PlatformType platformType = PlatformType::NULL_PTR;
};
class Platform : public GameObject {
public:
    Platform(const Object& object, const RGBa& rgba, Setting setting, PlatformType platformType)
            : GameObject(object, rgba, setting), platformType(platformType) {}

    Platform(const Object& object, const RGBa& rgba, PlatformType platformType)
            : GameObject(object, rgba), platformType(platformType) {
        addLayerTexture({{Texture({0,-15,TextureType::GRASS})}});
        addLayerTexture({{Texture({0,0,TextureType::GRASS_SURFACE})}});
        addLayerTexture({{Texture({0,5,TextureType::FILLER})}});


    }
    PlatformType getPlatformType(){return platformType;}
    static RGBa getPlatformColor(PlatformType platformType);

    void setTexture(SDL_Renderer* renderer);
    void addLayerTexture(Texture texture);
    void renderTexture(SDL_Renderer* renderer) const;

private:
    SDL_Texture * texture= nullptr;
    PlatformType platformType;
};

#endif //SDL_GAME_PLATFORM_H