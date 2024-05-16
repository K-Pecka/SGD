#include "Game.h"

std::vector<Wall> Game::walls;
std::vector<Platform> Game::platforms;

Game::Game(const GameConfig& gameConfig) : gameConfig(gameConfig), hero(Player(gameConfig.player,gameConfig.player.color)) {
    setWall();
    setPlatform();
}

void Game::setWall(){
    walls={
            Wall({0, 0, wallConfig.size.height, getGameConfig().screenSize.height}, wallConfig.color),
            Wall({getGameConfig().screenSize.width-wallConfig.size.height, 0, wallConfig.size.height, getGameConfig().screenSize.height}, wallConfig.color),

            Wall({0,0,getGameConfig().screenSize.width,wallConfig.size.height}, wallConfig.color),
            Wall({0,getGameConfig().screenSize.height-(wallConfig.size.height), getGameConfig().screenSize.width, wallConfig.size.height}, wallConfig.color)
    };
}
void Game::setPlatform(){
    for (const auto& platform : platformConfiguration) {
        if(platform.object.color.set)
            addPlatform(Platform(platform.object.size, platform.object.color,platform.platformType));
        else
            addPlatform(Platform(platform.object.size, Platform::getPlatformColor(platform.platformType),platform.platformType));
    }
}

GameObject * Game::checkCollisions(const Player& player) {
    const GameObject& playerObject = player;

    for (const auto& gameObject : platforms) {
        if (playerObject.checkCollision(gameObject)) {
            return (GameObject *) &gameObject;
        }
    }
    for (const auto& gameObject : walls) {
        if (playerObject.checkCollision(gameObject)) {
            return (GameObject *) &gameObject;
        }
    }

    return nullptr;
}
void Game::renderGameObjects(SDL_Renderer* Renderer) {

    for (auto obj : getPlatforms()) {
        obj.render(Renderer);
    }for (auto obj : getPlatforms()) {
        obj.setTexture(Renderer);
    }
    for (auto obj : getWalls()) {
        obj.render(Renderer);
    }
}
void Game::heroMove(int dx, int dy, Direction lastDirection) {
    getHero().move(dx, dy, lastDirection);

    if (auto* collisionObject = Game::checkCollisions(getHero())) {
        if(collisionObject->isMovable()) collisionObject->move(getHero().getDirection(),dx,dy);
        getHero().selectDirectionCollision(dx,dy);
    }
}

