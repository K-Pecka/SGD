#ifndef SDL_GAME_GAME_H
#define SDL_GAME_GAME_H

#include <vector>
#include "Player.h"

struct ScreenSize {
    int width = 200;
    int height = 200;
};
struct RGBa{
    int red=0;
    int green=0;
    int blue=0;
    int alfa=1;
};
struct Background{
    RGBa rgba{};
    const char * src = nullptr;
};
struct GameConfig{
    [[maybe_unused]] ScreenSize screenSize;
    const char * title = "TITLE UNKNOW";
    Background background;
    int FPS = 30;
    Hero player;
    bool set = false;

};
class GameObject {

public:
    explicit GameObject(Object object): x(object.x),y(object.y),width(object.w),height(object.h) {}

    GameObject()=default;

    int getX() const { return x; }
    void setX(int X) { x = X; }

    int getY() const { return y; }
    void setY(int Y) { y = Y; }

    int getWidth() const { return width; }
    void setWidth(int W) { width = W; }

    int getHeight() const { return height; }
    void setHeight(int H) { height = H; }


    [[nodiscard]] bool checkCollision(GameObject rect) const
    {
        return (getX() < rect.getX() + rect.getWidth() &&
                getX() + getWidth() > rect.getX() &&
                getY() < rect.getY() + rect.getHeight() &&
                getY() + getHeight() > rect.getY());
    }
protected:
    int x;
    int y;
    int width;
    int height;
};
class Game {

    public:
        Game() = default;
        explicit Game(const GameConfig& gameConfig) : gameConfig(gameConfig), hero(Player(gameConfig.player)){
            addGameObject(GameObject({200, 200, 50, 50}));
            addGameObject(GameObject({300, 300, 50, 50}));
        }

        GameConfig gameConfig;
        Player getHero() {return hero;}
        std::vector<GameObject> getGameObject(){return GameObjects;}
        void addGameObject(const GameObject& gameObject) {
            GameObjects.push_back(gameObject);
        }
    private:
        Player hero;
        std::vector<GameObject> GameObjects;

};

#endif //SDL_GAME_GAME_H
