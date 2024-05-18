#include "Game.h"

std::vector<Wall> Game::walls;
std::vector<Platform> Game::platforms;
std::vector<Monster> Game::monsters;

Game::Game(const GameConfig& gameConfig) : gameConfig(gameConfig), hero(Player(gameConfig.player)) {
    setWall();
    setPlatform();
    setEntity();
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
    int dd = (dy == 0) ? Physics::getGravitation() : dy;

    int heroNextX = getHero().getX() + dx;
    int heroNextY = getHero().getY() + dd;

    Player playerCollision({heroNextX, heroNextY, getHero().getWidth(), getHero().getHeight()});
    GameObject* collisionObject = Game::checkCollisions(playerCollision);

    if (collisionObject) {
        collisionObject->toString();
        if (collisionObject->isMovable()) {
            collisionObject->move(getHero().getDirection(), dx, dd);
        }

        // Dostosowanie pozycji bohatera na podstawie kolizji
        if (dx != 0) {
            if (collisionObject->getX() > getHero().getX()) {
                getHero().setDirection(Direction::LEFT);
            } else {
                getHero().setDirection(Direction::RIGHT);
            }
        }

        if (dd != 0) {
            if (collisionObject->getY() > getHero().getY()) {
                // Kolizja od góry
                getHero().setY(collisionObject->getY() - getHero().getHeight());
            } else {
                // Kolizja od dołu
                getHero().setY(collisionObject->getY() + collisionObject->getHeight());
            }
        }

        getHero().selectDirectionCollision(dx, dd);
        getHero().collision();
    } else {
        getHero().move(dx, dd, lastDirection);
    }

    if (!getHero().getSpeed().gravity) {
        Player groundCheck({getHero().getX(), getHero().getY() + getHero().getHeight(), getHero().getWidth(), 5});
        collisionObject = Game::checkCollisions(groundCheck);
        if (collisionObject == nullptr) {
            getHero().fall();
        }
    }
}
void Game::updateMonster()
{
        for (auto &monster : monsters) {
            if (monster.getX() <= monster.getMonsterConfig().min_X || monster.getX() >= monster.getMonsterConfig().max_X) {
               monster.changeDirection();
            }
            monster.move();
        }
}
void Game::setEntity() {
    setMonster();
}
int randomInt(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min,max);
    return dis(gen);
}
void Game::setMonster() {
    monsters = {
            Monster({
                {70,90,30,40},
                {205,205,205},
                {9,0}},
                    {70,250,-1}),
            Monster({
                            {510,260,30,40},
                            {205,205,205},
                            {9,0}},
                    {510,690,-1}),
    };
    for (auto &monster : monsters) {
        int xMove=randomInt(monster.getMonsterConfig().min_X,monster.getMonsterConfig().max_X);
        monster.move(xMove);
    }
}
void Game::updateEntity() {
    updateMonster();
}

void Game::entityRender(SDL_Renderer* renderer) {
    for(Monster monster:monsters)
    {
        monster.render(renderer);
    }
}
