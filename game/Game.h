#ifndef SDL_GAME_GAME_H
#define SDL_GAME_GAME_H

#include <vector>
#include <memory>
#include <random>

#include "../game/physics/Physics.h"
#include "gameObject/wall/Wall.h"
#include "gameObject/platform/Platform.h"
#include "gameObject/Entity/player/Player.h"
#include "../game/gameObject/entity/enemy/monster/Monster.h"

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
        static void updateEntity(SDL_Renderer*);
        static void setEntity();
        static void entityRender(SDL_Renderer*);

        static void updateMonster(SDL_Renderer*);
        static void setMonster();
        void heroMove(int ,int,Direction);
        [[maybe_unused]] static void renderGameObjects(SDL_Renderer*);
        [[maybe_unused]] static GameObject * checkCollisions(const Player&);

    private:
        GameConfig gameConfig;
        Player hero;

        std::vector<PlatformConfig> platformConfiguration={
                {{0,450,200,40},PlatformType::GRASS},
                {{210,480,200,20},PlatformType::FILLER},
                {{400,520,60,20},PlatformType::FILLER},
                {{470,470,60,20},PlatformType::FILLER},
                {{540,440,60,20},PlatformType::FILLER},
                {{610,420,200,20},PlatformType::FILLER},
                {{740,360,60,20},PlatformType::FILLER},
                {{510,300,200,20},PlatformType::FILLER},
                {{680,130,80,20},PlatformType::GOAL},
                {{310,330,140,20},PlatformType::FILLER},
                {{90,280,140,20},PlatformType::FILLER},
                {{10,220,60,20},PlatformType::FILLER},
                {{70,130,200,20},PlatformType::FILLER},
                {{320,130,80,20},PlatformType::FILLER},
                {{500,150,80,20},PlatformType::FILLER}
        };
        static std::vector<Wall> walls;
        static std::vector<Platform> platforms;
        static std::vector<Monster> monsters;

};

#endif //SDL_GAME_GAME_H
