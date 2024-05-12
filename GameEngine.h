#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <SDL.h>
#include <SDL_timer.h>
#include <iostream>
#include <utility>
#include <vector>
#include "Message.h"
#include "Game.h"

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

    Game game;
    Message message;
    bool runGame = true;


    void createWindow(GameConfig);
    void sdlInit();
    void createRender();
    void setRenderBackground(Background);

    SDL_Surface * setSurface(Background);

    [[maybe_unused]] static bool checkCollisions(Player, const std::vector<GameObject>&);
};

#endif // GAME_ENGINE_H
