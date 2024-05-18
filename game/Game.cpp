#include "Game.h"

std::vector<Wall> Game::walls;
std::vector<Platform> Game::platforms;

Game::Game(const GameConfig& gameConfig) : gameConfig(gameConfig), hero(Player(gameConfig.player)) {
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
            std::cout<<"kolizja P"<<std::endl;
            return (GameObject *) &gameObject;
        }
    }
    for (const auto& gameObject : walls) {
        if (playerObject.checkCollision(gameObject)) {
            std::cout<<"kolizja W"<<std::endl;
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
    int dd = (dy == 0) ? Physics::getGravitation() : dy;

    int heroY = getHero().getY();
    int heroNextY = heroY + dd;
    int dyPlayerStart = std::min(heroY, heroNextY);
    int dyPlayerEnd = std::max(heroY, heroNextY);

    int heroX = getHero().getX();
    int heroNextX = heroX + dx;
    int dxPlayerStart = std::min(heroX, heroNextX);
    int dxPlayerEnd = std::max(heroX, heroNextX);

    if(getHero().getSpeed().vy != 0)
    {
        for(int y=dyPlayerStart;y<=dyPlayerEnd;y++)
        {
            for(int x=dxPlayerStart;x<=dxPlayerEnd;x++) {
                Player playerCollision({x, y, getHero().getHeight(), getHero().getWidth()});
                if (auto *collisionObject = Game::checkCollisions(playerCollision)) {
                    if (collisionObject->isMovable()) collisionObject->move(getHero().getDirection(), dx, dy);
                    getHero().selectDirectionCollision(dx, dy);
                    getHero().collision();
                    getHero().move(0, -1, lastDirection);
                    std::cout<<"kk"<<std::endl;
                    break;
                }
            }
        }
    }
    if(getHero().getSpeed().vy == 0)
    {
        Player playerCollision({getHero().getX(),getHero().getY(),getHero().getWidth(),getHero().getHeight()+15});
        auto* collisionObject = Game::checkCollisions(playerCollision);
        if (collisionObject == nullptr) {
            getHero().fall();
        }
    }


    getHero().move(dx, dy, lastDirection);
}

