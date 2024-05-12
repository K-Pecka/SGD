#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <SDL.h>
#include <iostream>
#include "Message.h"
#include "Game.h"


class GameEngine {
public:
    SDL_Window* Window = nullptr;
    SDL_Renderer* Renderer = nullptr;
    SDL_Texture* texture = nullptr;
    Game game;
    Message message;
    void close();


    explicit GameEngine(const Game& gameSet) : game(gameSet) {}

    ~GameEngine();
    bool runGame = true;
    bool init();
    void run();

};

#endif // GAME_ENGINE_H
