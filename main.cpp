#include "GameEngine.h"
#include "Game.h"


int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
    ScreenSize screenSize = {800,600};
    const char * title = "GRA SDL2";
    Background background = {{10,20,20},"background.bmp"};

    GameConfig gameConfig = {
            screenSize,
            title,
            background,
            60,
            {{int(screenSize.width/2), int(screenSize.height/2), 50, 50 } ,10},
            true
    };
    Game game(gameConfig);
    GameEngine engine(game);

    engine.init();
    engine.run();

    return 0;
}