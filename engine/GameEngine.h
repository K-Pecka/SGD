#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <SDL.h>
#include <SDL_timer.h>
#include <iostream>
#include <utility>
#include <vector>
#include "../game/Game.h"
#include <unordered_map>
#include "../tool/Message.h"

class GameEngine {
public:
    explicit GameEngine(const Game&  gameSet) : game(std::move(gameSet)) {}
    ~GameEngine();
    void run();
    void close(int);
    void setFPS();
    static Direction checkDirection(SDL_Keycode,Direction );
    void init();

private:
    SDL_Event event{};
    Uint32 frameStart{};
    Uint32 frameTime{};
    std::unordered_map<SDL_Keycode, bool> keys;

    SDL_Window* Window = nullptr;
    SDL_Renderer* Renderer = nullptr;
    SDL_Surface* Surface = nullptr;
    SDL_Texture* texture = nullptr;


    Game game;
    Message message;
    bool runGame = true;

    bool clickExit(Uint32,Uint32);
    void setRenderBackground(Background);
    SDL_Surface * setSurface(const Background&);
    [[maybe_unused]] void renderBackground();

    void createWindow(GameConfig);
    void sdlInit();
    void createRender();
};

#endif // GAME_ENGINE_H
