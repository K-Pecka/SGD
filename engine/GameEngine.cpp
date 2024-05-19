#include "GameEngine.h"

GameEngine::~GameEngine() {close(0);}
SDL_Surface * GameEngine::setSurface(const Background& background) {
    Surface = SDL_LoadBMP(background.src);
    if (Surface == nullptr) {
        std::cerr << "bmp error";
        exit(0);
    }
    return  Surface;
}

void GameEngine::createWindow(GameConfig config)
{
    Window=SDL_CreateWindow(config.title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, int(config.screenSize.width),int(config.screenSize.height),SDL_WINDOW_SHOWN);
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
    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (Renderer == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s SDL error: %s",message.getErrorMessage(ErrorType::RENDER).c_str(), SDL_GetError());
        message.showMessageBox(ErrorType::RENDER,ErrorMessageType::MERROR);
        exit(0);
    }
}

void GameEngine::init() {

    createWindow(game.getGameConfig());
    sdlInit();
    createRender();

    if (!game.getGameConfig().set) {
        std::cout <<message.getErrorMessage(ErrorType::SET)  << std::endl;
        message.showMessageBox(ErrorType::SET,ErrorMessageType::MWARNING);
    }

    texture = SDL_CreateTextureFromSurface(Renderer, setSurface(game.getGameConfig().background));

    SDL_FreeSurface(Surface);

    if (texture == nullptr) {
        std::cerr<<"texture error";
        exit(0);
    }
    setRenderBackground(game.getGameConfig().background);
    run();
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
bool GameEngine::clickExit(Uint32 eventClick, Uint32  key)
{
    if(eventClick!=key) return true;
    close(0);
    return false;
}

void GameEngine::run()
{
    int frame=0;
    Direction lastDirection = game.getHero().getDirection();
    while (runGame) {
        frameStart = SDL_GetTicks();
        int dx = 0;
        while (SDL_PollEvent(&event) != 0) {
            clickExit(event.type,SDL_QUIT);
            if (event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.sym == SDLK_SPACE)
                {
                    game.getHero().setSpeed({game.getHero().getSpeedX(),-20,true});
                }
            }

            if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
                keys[event.key.keysym.sym] = (event.type == SDL_KEYDOWN);
                lastDirection = checkDirection(event.key.keysym.sym, lastDirection);
            }
        }
        frame++;

        if(frame % 5 == 0) game.updateEntity();

        if (keys[SDLK_LEFT]) dx -= game.getHero().getSpeed().vx;
        if (keys[SDLK_RIGHT]) dx += game.getHero().getSpeed().vx;

        SDL_RenderClear(Renderer);
        renderBackground();

        game.getHero().update(Renderer);
        game.heroMove(dx, 0, lastDirection);
        game.entityRender(Renderer);

        Game::renderGameObjects(Renderer);
        SDL_RenderPresent(Renderer);
        setFPS();
    }
    close(0);
}
void GameEngine::setRenderBackground(Background background)
{
    SDL_SetRenderDrawColor(Renderer, background.rgba.red, background.rgba.green, background.rgba.blue, background.rgba.alfa);
}
void GameEngine::renderBackground()
{
    SDL_RenderCopy(Renderer, texture, nullptr, nullptr);
}
void GameEngine::setFPS()
{
    frameTime = SDL_GetTicks() - frameStart;
    if (frameTime < 1000 / game.getGameConfig().FPS) {
        SDL_Delay((1000 / game.getGameConfig().FPS) - frameTime);
    }
}
void GameEngine::close(int code) {
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    Renderer = nullptr;
    Window = nullptr;
    SDL_Quit();
    exit(0);
}
