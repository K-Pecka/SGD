#include "engine/GameEngine.h"
#include "game/Game.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {

    ScreenSize screenSize = {800,600};

    GameConfig gameConfig =
            {
            screenSize,
            "GRA SDL2",
            {{10,20,20},"background.bmp"},
            60,
            {{int(screenSize.width/2), int(screenSize.height/2), 70, 90 } ,10},
            true
            };

    Game game(gameConfig);
    GameEngine engine(game);

    engine.init();

    return 0;
}