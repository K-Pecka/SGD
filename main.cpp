#include "GameEngine.h"
#include "Game.h"


int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
    ScreenSize screenSize = {800,600};
    const char * title = "GRA PODSTAWY, PODSTWY SDL2";
    Background background = {{10,20,20},"background.bmp"};

    GameConfig gameConfig = {
            screenSize,
            title,
            background,
            true
    };
    Game game(gameConfig);
    GameEngine engine(game);

    engine.init();
    engine.run();

    return 0;
}