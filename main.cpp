#include "engine/GameEngine.h"
#include "game/Game.h"
int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {

    ScreenSize screenSize = {800,600};

    GameConfig gameConfig =
            {
            screenSize,
            "GRA SDL2",
            {{10,20,20},"../asset/background.bmp"},
            60,
            {{(40), (300), 30, 40 } ,{1,2,3},{5,1}},
            true
            };

    Game game(gameConfig);
    GameEngine engine(game);

    engine.init();

    return 0;
}