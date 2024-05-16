#ifndef SDL_GAME_GAME_H
#define SDL_GAME_GAME_H

#include <vector>
#include <memory>
#include "player/Player.h"
#include "gameObject/wall/Wall.h"
#include "gameObject/platform/Platform.h"

struct ScreenSize {
    float width = 200;
    float height = 200;
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
struct PlatformSize{
    float height = 20;
    float width = 20;
};
struct ObjectConfig{
    PlatformSize minSize = {50,10};
    RGBa color = {23,23,23};
};
struct Coordinates{ float x;float y;};

static ObjectConfig wallConfig={{5}, {23, 23, 23}};
static ObjectConfig platformConfig={{5,50},{230,23,23}};

class Game {

    public:
        Game() = delete;
        explicit Game(const GameConfig& gameConfig);


        Player& getHero() { return hero; }
        GameConfig getGameConfig() { return gameConfig; }

        static std::vector<Wall>& getWalls() { return walls; }
        static void addWall(const Wall& wall) { walls.push_back(wall); }
        static std::vector<Platform>& getPlatforms() { return platforms; }
        static void addPlatform(const Platform& platform) { platforms.push_back(platform); }

        void setWall();
        void setPlatform();
        void heroMove(float ,float,Direction);
        [[maybe_unused]] static void renderGameObjects(SDL_Renderer*);
        [[maybe_unused]] static GameObject * checkCollisions(const Player&);

    private:
        GameConfig gameConfig;
        Player hero;

        std::vector<Coordinates> coordinates={
                {0,  100},{60, 200},
                {50,  100},{90, 90}
        };
        static std::vector<Wall> walls;
        static std::vector<Platform> platforms;

};

#endif //SDL_GAME_GAME_H
