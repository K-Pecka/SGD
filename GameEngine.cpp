#include "GameEngine.h"

GameEngine::~GameEngine() {
    close();
}

bool GameEngine::init() {
    if (!game.gameConfig.set) {
        std::cout <<message.getErrorMessage(ErrorType::SET)  << std::endl;
        message.showMessageBox(ErrorType::SET,ErrorMessageType::MWARNING);
    }
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s SDL error: %s", message.getErrorMessage(ErrorType::INIT).c_str(), SDL_GetError());
        message.showMessageBox(ErrorType::INIT,ErrorMessageType::MERROR);
        return false;
    }

    Window = SDL_CreateWindow(this->game.gameConfig.title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->game.gameConfig.screenSize.width,this->game.gameConfig.screenSize.height,SDL_WINDOW_SHOWN);

    if (Window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s SDL error: %s", message.getErrorMessage(ErrorType::CREATE).c_str(), SDL_GetError());
        message.showMessageBox(ErrorType::CREATE,ErrorMessageType::MERROR);
        return false;
    }

    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
    if (Renderer == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s SDL error: %s", message.getErrorMessage(ErrorType::RENDER).c_str(), SDL_GetError());
        message.showMessageBox(ErrorType::RENDER,ErrorMessageType::MERROR);
        return false;
    }

    SDL_Surface *surface = SDL_LoadBMP(game.gameConfig.background.src);
    if (surface == nullptr) {
        std::cerr<<"bmp error";
    }
    texture = SDL_CreateTextureFromSurface(Renderer, surface);

    SDL_FreeSurface(surface);
    if (texture == nullptr) {
        std::cerr<<"texture error";
    }

    SDL_SetRenderDrawColor(Renderer, game.gameConfig.background.rgba.red, game.gameConfig.background.rgba.green, game.gameConfig.background.rgba.blue, game.gameConfig.background.rgba.alfa);
    return true;
}
void GameEngine::run()
{

    SDL_Event e;
    while (runGame) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                runGame=false;
            }
        }

        SDL_RenderClear(Renderer);

        SDL_RenderCopy(Renderer, texture, nullptr, nullptr);


        SDL_RenderPresent(Renderer);
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





