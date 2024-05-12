#ifndef SDL_GAME_GAME_H
#define SDL_GAME_GAME_H


struct ScreenSize {
    int width = 200;
    int height = 200;
};
struct RGBa{
    int red=0;
    int green=0;
    int blue=0;
    int alfa=1;
};
struct Background{
    RGBa rgba{};
    const char * src = nullptr;
};
struct GameConfig{
    [[maybe_unused]] ScreenSize screenSize;
    const char * title = "TITLE UNKNOW";
    Background background;
    bool set = false;
};

class Game {

    public:
        Game() = default;
        explicit Game(const GameConfig& gameConfig) : gameConfig(gameConfig){}

        GameConfig gameConfig;

    private:


};

#endif //SDL_GAME_GAME_H
