#include "../GameObject.h"
#ifndef SDL_GAME_PLATFORM_H
#define SDL_GAME_PLATFORM_H

enum class PlatformType{
    FILLER,GRASS,METAL,NULL_PTR
};
struct PlatformConfig{
    ObjectConfig object;
    PlatformType platformType = PlatformType::NULL_PTR;
};
class Platform: public GameObject {
public:
    Platform(const Object& object, const RGBa& rgba,Setting setting,SettingPhysics settingPhysics,PlatformType platformType): platformType(platformType),GameObject(object,rgba,setting,settingPhysics) {}
    Platform(const Object& object, const RGBa& rgba,PlatformType platformType): platformType(platformType), GameObject(object,rgba) {}
    static RGBa getPlatformColor(PlatformType);
    static char * getPlatformTexture(PlatformType);

    void setTexture(SDL_Renderer*);
    void repeatTexture(SDL_Renderer*);
private:

    SDL_Texture* texture;
    PlatformType platformType;
};


#endif //SDL_GAME_PLATFORM_H
