#include "../GameObject.h"
#ifndef SDL_GAME_PLATFORM_H
#define SDL_GAME_PLATFORM_H


class Platform: public GameObject {
public:
    Platform(const Object& object, const RGBa& rgba,Setting setting,SettingPhysics settingPhysics): GameObject(object,rgba,setting,settingPhysics) {}
    Platform(const Object& object, const RGBa& rgba): GameObject(object,rgba) {}
};


#endif //SDL_GAME_PLATFORM_H
