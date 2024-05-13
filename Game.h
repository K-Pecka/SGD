#ifndef SDL_GAME_GAME_H
#define SDL_GAME_GAME_H

#include <vector>
#include <memory>
#include "Player.h"
#include "GameObject.h"

struct ScreenSize {
    int width = 200;
    int height = 200;
};
struct Background{
    RGBa rgba{};
    const char * src = nullptr;
};
struct GameConfig{
    [[maybe_unused]] ScreenSize screenSize;
    const char * title = "TITLE UNKNOWN";
    Background background;
    int FPS = 30;
    Hero player;
    bool set = false;

};
class Game {

    public:
        Game() = default;
        explicit Game(const GameConfig& gameConfig) : gameConfig(gameConfig), hero(Player(gameConfig.player)) {
            int minSize = 10;
            addGameObject(GameObject({0,0,minSize,gameConfig.screenSize.height},{0,255,3,1}));
            addGameObject(GameObject({gameConfig.screenSize.width-minSize,0,minSize,gameConfig.screenSize.height},{0,255,3,1}));

            addGameObject(GameObject({0,0,gameConfig.screenSize.width,minSize},{0,255,3,1}));
            addGameObject(GameObject({0,gameConfig.screenSize.height-minSize,gameConfig.screenSize.width,minSize},{0,255,3,1}));

            addGameObject(GameObject({150,150,50,50},{10,260,30,1},true));
            addGameObject(GameObject({200,200,50,50},{1,2,3,1},true));
            addGameObject(GameObject({250,250,50,50},{10,260,30,1}));
        }

        GameConfig gameConfig;
        Player& getHero() { return hero; }
        std::vector<GameObject>& getGameObjects() { return gameObjects; }
        void addGameObject(const GameObject& gameObject) { gameObjects.push_back(gameObject); }
    private:
        Player hero;
        std::vector<GameObject> gameObjects;

};

#endif //SDL_GAME_GAME_H
