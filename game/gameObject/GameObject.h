#include <iostream>
#include <vector>
#include <SDL.h>
#include "../physics/Physics.h"

#ifndef SDL_GAME_GAME_OBJECT_H
#define SDL_GAME_GAME_OBJECT_H

enum class Direction{
    LEFT,RIGHT,UP,DOWN
};
struct Object{
    float x = 0;
    float y = 0;
    float w = 50;
    float h = 50;
};
struct RGBa{
    int red=0;
    int green=0;
    int blue=0;
    int alfa=1;
};
struct Setting{
    bool movable= false;
    bool gravityable = false;
};

class GameObject : public Physics{

public:

    GameObject(Object object,RGBa rgba,Setting setting,SettingPhysics settingPhysics):
        x(object.x),y(object.y),width(object.w),height(object.h),rgba(rgba),setting(setting),Physics(settingPhysics) {}

    GameObject(Object object,RGBa rgba):
        x(object.x),y(object.y),width(object.w),height(object.h),rgba(rgba),setting({}),Physics(basePhysics) {}

    explicit GameObject(Object object) :
        x(object.x), y(object.y), width(object.w),height(object.h),Physics(basePhysics) {}

    GameObject()=default;

    float getX() const { return x; }
    void setX(float X) { x = X; }
    void setXplus(float X) { x+=X;}

    float getY() const { return y; }
    void setY(float Y) { y = Y; }
    void setYplus(float Y) { y+=Y;}

    RGBa getRGBa() const { return rgba; }
    void setRGBa(RGBa Rgba) { rgba = Rgba; }

    float getWidth() const { return width; }
    void setWidth(float W) { width = W; }

    float getHeight() const { return height; }
    void setHeight(float H) { height = H; }


    bool isMovable(){return setting.movable;}
    void move(Direction,float,float);
    void render(SDL_Renderer*);

    virtual void toString() const;

    [[nodiscard]] bool checkCollision(const GameObject& rect) const {
        return (getX() < rect.getX() + rect.getWidth() &&
                getX() + getWidth() > rect.getX() &&
                getY() < rect.getY() + rect.getHeight() &&
                getY() + getHeight() > rect.getY());
    }
protected:
    SettingPhysics basePhysics={9.8f,5};
    float x;
    float y;
    float width;
    float height;
    Setting setting;
    RGBa rgba{255,255,255,1};

    void update(GameObject &obj);
};


#endif //SDL_GAME_GAME_OBJECT_H
