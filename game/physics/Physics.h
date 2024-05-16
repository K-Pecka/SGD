//
// Created by Kacper on 15.05.2024.
//

#ifndef SDL_GAME_PHYSICS_H
#define SDL_GAME_PHYSICS_H

struct SettingPhysics{
    float gravity=9.8f;
    float speed=5;
};

class Physics {
public:
    explicit Physics(SettingPhysics setting): gravity(setting.gravity),speed(setting.speed){}
    Physics() =default;
    //void setGravitation(const GameObject& gameObject&);
private:
    float speed;
    float gravity;
};


#endif //SDL_GAME_PHYSICS_H
