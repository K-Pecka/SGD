#include "Game.h"

std::vector<Wall> Game::walls;
std::vector<Platform> Game::platforms;

Game::Game(const GameConfig& gameConfig) : gameConfig(gameConfig), hero(Player(gameConfig.player)) {
    setWall();
    setPlatform();
}

void Game::setWall(){
    walls={
            Wall({0,0,wallConfig.minSize.height,getGameConfig().screenSize.height},wallConfig.color),
            Wall({getGameConfig().screenSize.width-wallConfig.minSize.height,0,wallConfig.minSize.height,getGameConfig().screenSize.height},wallConfig.color),

            Wall({0,0,getGameConfig().screenSize.width,wallConfig.minSize.height},wallConfig.color),
            Wall({0,getGameConfig().screenSize.height-(wallConfig.minSize.height),getGameConfig().screenSize.width,wallConfig.minSize.height},wallConfig.color)
    };
}
void Game::setPlatform(){
    for (const auto& platform : coordinates) {
        addPlatform(Platform({platform.x,platform.y,platformConfig.minSize.width,platformConfig.minSize.height},platformConfig.color));
    }
    addPlatform(Platform({0,getGameConfig().screenSize.height-(wallConfig.minSize.height*5),getGameConfig().screenSize.width,wallConfig.minSize.height*5},wallConfig.color));
}

GameObject * Game::checkCollisions(const Player& player) {
    const GameObject& playerObject = player;

    for (const auto& gameObject : walls) {
        if (playerObject.checkCollision(gameObject)) {
            return (GameObject *) &gameObject;
        }
    }
    for (const auto& gameObject : platforms) {
        if (playerObject.checkCollision(gameObject)) {
            return (GameObject *) &gameObject;
        }
    }
    return nullptr;
}
void Game::renderGameObjects(SDL_Renderer* Renderer) {
    for (auto obj : getWalls()) {
        obj.render(Renderer);
    }
    for (auto obj : getPlatforms()) {
        obj.render(Renderer);
    }
}