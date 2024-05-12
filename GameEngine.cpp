#include "GameEngine.h"
#include "Player.h"
#include <unordered_map>
GameEngine::~GameEngine() {
    close();
}
void GameEngine::createWindow(GameConfig config)
{
    Window=SDL_CreateWindow(config.title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, config.screenSize.width,config.screenSize.height,SDL_WINDOW_SHOWN);
    if (Window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s SDL error: %s", message.getErrorMessage(ErrorType::CREATE).c_str(), SDL_GetError());
        message.showMessageBox(ErrorType::CREATE,ErrorMessageType::MERROR);
        exit(0);
    }
}
void GameEngine::sdlInit()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s SDL error: %s", message.getErrorMessage(ErrorType::INIT).c_str(), SDL_GetError());
        message.showMessageBox(ErrorType::INIT,ErrorMessageType::MERROR);
        exit(0);
    }
}
void GameEngine::createRender()
{
    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
    if (Renderer == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s SDL error: %s", message.getErrorMessage(ErrorType::RENDER).c_str(), SDL_GetError());
        message.showMessageBox(ErrorType::RENDER,ErrorMessageType::MERROR);
        exit(0);
    }
}
void GameEngine::setRenderBackground(Background background)
{
    SDL_SetRenderDrawColor(Renderer, background.rgba.red, background.rgba.green, background.rgba.blue, background.rgba.alfa);
}
SDL_Surface * GameEngine::setSurface(Background background) {
    Surface = SDL_LoadBMP(background.src);
    if (Surface == nullptr) {
        std::cerr << "bmp error";
        exit(0);
    }
    return  Surface;
}
void GameEngine::init() {

    createWindow(game.gameConfig);
    sdlInit();
    createRender();

    if (!game.gameConfig.set) {
        std::cout <<message.getErrorMessage(ErrorType::SET)  << std::endl;
        message.showMessageBox(ErrorType::SET,ErrorMessageType::MWARNING);
    }

    texture = SDL_CreateTextureFromSurface(Renderer, setSurface(game.gameConfig.background));

    SDL_FreeSurface(Surface);

    if (texture == nullptr) {
        std::cerr<<"texture error";
        exit(0);
    }
    setRenderBackground(game.gameConfig.background);
}

[[maybe_unused]] bool GameEngine::checkCollisions(Player player, const std::vector<GameObject>& gameObjects) {
    GameObject playerObject = reinterpret_cast<GameObject &&>(player);
    for (const auto& gameObject : gameObjects) {
        if (playerObject.checkCollision(gameObject))
        {
            return true;
        }
    }
    return false;
}
Direction GameEngine::checkDirection(SDL_Keycode key, Direction lastKey) {
    switch (key) {
        case SDLK_UP:
            return Direction::UP;
        case SDLK_DOWN:
            return Direction::DOWN;
        case SDLK_LEFT:
            return Direction::LEFT;
        case SDLK_RIGHT:
            return Direction::RIGHT;
        default:
            return lastKey;
    }
}
void GameEngine::run()
{
    SDL_Event event;
    Uint32 frameStart;
    Uint32 frameTime;
    std::unordered_map<SDL_Keycode, bool> keys;

    SDL_Rect obstacle = {400, 100, 100, 100};
    Direction lastDirection = game.getHero().getDirection();
    while (runGame) {
        frameStart = SDL_GetTicks();
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                runGame = false;
            } else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
                keys[event.key.keysym.sym] = (event.type == SDL_KEYDOWN);
                lastDirection = checkDirection(event.key.keysym.sym, lastDirection);
            }
        }

        int dx = 0, dy = 0;
        if (keys[SDLK_UP]) dy -= game.getHero().getSpeed();
        if (keys[SDLK_DOWN]) dy += game.getHero().getSpeed();
        if (keys[SDLK_LEFT]) dx -= game.getHero().getSpeed();
        if (keys[SDLK_RIGHT]) dx += game.getHero().getSpeed();

        game.getHero().move(dx, dy, lastDirection);

        SDL_RenderClear(Renderer);
        SDL_RenderCopy(Renderer, texture, nullptr, nullptr);

        SDL_Rect playerRect = game.getHero().getObject();
        SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(Renderer, &playerRect);

        SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(Renderer, &obstacle);

        if (checkCollisions(game.getHero(), game.getGameObject())) {
            switch (game.getHero().getDirection()) {
                case Direction::LEFT:
                    game.getHero().move(-dx, 0, Direction::RIGHT);
                    obstacle.x+=dx+1;
                    break;
                case Direction::RIGHT:
                    game.getHero().move(-dx, 0, Direction::LEFT);
                    obstacle.x+=dx+1;
                    break;
                case Direction::UP:
                    game.getHero().move(0, -dy, Direction::DOWN);
                    obstacle.y+=dy;
                    break;
                case Direction::DOWN:
                    game.getHero().move(0, -dy, Direction::UP);
                    obstacle.y+=dy+1;
                    break;
            }
        }

        SDL_RenderPresent(Renderer);

        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < 1000 / game.gameConfig.FPS) {
            SDL_Delay((1000 / game.gameConfig.FPS) - frameTime);
        }
    }
    close();
}
void GameEngine::close() {
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    Renderer = nullptr;
    Window = nullptr;
    SDL_Quit();
}





