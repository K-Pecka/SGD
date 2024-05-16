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
    int x = 0;
    int y = 0;
    int width = 50;
    int height = 50;
};
struct RGBa{
    int red=0;
    int green=0;
    int blue=0;
    int alfa=1;
    bool set=false;
};
struct Setting{
    bool movable= false;
    bool gravityable = false;
};

struct ObjectConfig{
    Object size = {50, 10};
    RGBa color = {23,23,23};
};
class GameObject : public Physics{

public:

    GameObject(Object object,RGBa rgba,Setting setting,SettingPhysics settingPhysics):
        x(object.x),y(object.y),width(object.width),height(object.height),rgba(rgba),setting(setting),Physics(settingPhysics) {}

    GameObject(Object object,RGBa rgba):
        x(object.x),y(object.y),width(object.width),height(object.height),rgba(rgba),setting({}),Physics(basePhysics) {}

    explicit GameObject(Object object) :
        x(object.x), y(object.y), width(object.width),height(object.height),Physics(basePhysics) {}

    GameObject()=default;

    int getX() const { return x; }
    void setX(int X) { x = X; }
    void setXplus(int X) { x+=X;}

    float getY() const { return y; }
    void setY(int Y) { y = Y; }
    void setYplus(int Y) { y+=Y;}

    RGBa getRGBa() const { return rgba; }
    void setRGBa(RGBa Rgba) { rgba = Rgba; }

    int getWidth() const { return width; }
    void setWidth(int W) { width = W; }

    int getHeight() const { return height; }
    void setHeight(int H) { height = H; }


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
    int x;
    int y;
    int width;
    int height;
    Setting setting;
    RGBa rgba{255,255,255,1};

    void update(GameObject &obj);
};


#endif //SDL_GAME_GAME_OBJECT_H
