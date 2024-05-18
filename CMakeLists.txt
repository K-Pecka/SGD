cmake_minimum_required(VERSION 3.27)
project(SDL_game)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_INCLUDE_DIR "C:\\Users\\Kacper\\Dev\\tool\\SDL\\SDL2-2.30.1\\include")
set(SDL2_LIB_DIR "C:\\Users\\Kacper\\Dev\\tool\\SDL\\SDL2-2.30.1\\lib\\x64")

include_directories(${SDL2_INCLUDE_DIR})
add_executable(${PROJECT_NAME} main.cpp
        game/Game.cpp
        game/Game.h
        tool/Message.cpp
        tool/Message.h
        engine/GameEngine.cpp
        engine/GameEngine.h
        game/gameObject/Entity/player/Player.cpp
        game/gameObject/Entity/player/Player.h
        game/gameObject/GameObject.cpp
        game/gameObject/GameObject.h
        game/physics/Physics.cpp
        game/physics/Physics.h
        game/gameObject/wall/Wall.cpp
        game/gameObject/wall/Wall.h
        game/gameObject/platform/Platform.cpp
        game/gameObject/platform/Platform.h
        game/gameObject/Entity/enemy/Enemy.cpp
        game/gameObject/Entity/enemy/Enemy.h
        game/gameObject/Entity/Entity.cpp
        game/gameObject/Entity/Entity.h

)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIB_DIR}/SDL2.lib ${SDL2_LIB_DIR}/SDL2main.lib)
