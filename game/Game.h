#ifndef SDL_GAME_GAME_H
#define SDL_GAME_GAME_H

#include <vector>
#include <memory>
#include "../game/physics/Physics.h"
#include "gameObject/wall/Wall.h"
#include "gameObject/platform/Platform.h"
#include "gameObject/Entity/player/Player.h"

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
    EntityCreator player;
    bool set = false;

};

static ObjectConfig wallConfig={{0,0,0,5}, {23, 23, 23}};
static ObjectConfig platformConfig={{0,0,5,50},{230,23,23}};

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
        void heroMove(int ,int,Direction);
        [[maybe_unused]] static void renderGameObjects(SDL_Renderer*);
        [[maybe_unused]] static GameObject * checkCollisions(const Player&);

    private:
        GameConfig gameConfig;
        Player hero;

        std::vector<PlatformConfig> platformConfiguration={
                {{{0,100,40,40}},PlatformType::GRASS},
                {{{100,100,40,40}},PlatformType::FILLER},
                {{{10,500,500,40}},PlatformType::FILLER}
        };
        static std::vector<Wall> walls;
        static std::vector<Platform> platforms;

};

#endif //SDL_GAME_GAME_H
