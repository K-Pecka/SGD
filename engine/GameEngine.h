#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <SDL.h>
#include <SDL_timer.h>
#include <iostream>
#include <utility>
#include <vector>

#include "../librarie/SDL_ttf.h"
#include "../tool/Message.h"
#include "../game/Game.h"

class GameEngine {
public:
    explicit GameEngine(Game  gameSet) : game(std::move(gameSet)) {}
    ~GameEngine();
    void init();
    void run();
    void close();

    static Direction checkDirection(SDL_Keycode,Direction );


private:
    SDL_Window* Window = nullptr;
    SDL_Renderer* Renderer = nullptr;
    SDL_Surface* Surface = nullptr;
    SDL_Texture* texture = nullptr;
    //TTF_Font* Font = nullptr;
    //SDL_Texture* TextTexture = nullptr;

    Game game;
    Message message;
    bool runGame = true;

    void createWindow(GameConfig);
    void sdlInit();
    void createRender();
    void setRenderBackground(Background);
    SDL_Surface * setSurface(Background);

};

#endif // GAME_ENGINE_H
