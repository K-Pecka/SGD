#ifndef SDL_GAME_PLATFORM_H
#define SDL_GAME_PLATFORM_H

#include "../../../texture/Texture.h"
#include "../GameObject.h"
enum class PlatformType {
    FILLER, GRASS, METAL, NULL_PTR
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
        addLayerTexture({{Texture({0,-5,TextureType::GRASS})}});
        addLayerTexture({{Texture({0,0,TextureType::FILLER})}});


    }

    static RGBa getPlatformColor(PlatformType platformType);

    void setTexture(SDL_Renderer* renderer);
    void addLayerTexture(Texture texture);
    void renderTexture(SDL_Renderer* renderer) const;

private:
    SDL_Texture * texture= nullptr;
    PlatformType platformType;
};

#endif //SDL_GAME_PLATFORM_H