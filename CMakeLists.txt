cmake_minimum_required(VERSION 3.27)
project(SDL_game)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_INCLUDE_DIR "C:\\Users\\Kacper\\Dev\\tool\\SDL\\SDL2-2.30.1\\include")
set(SDL2_LIB_DIR "C:\\Users\\Kacper\\Dev\\tool\\SDL\\SDL2-2.30.1\\lib\\x64")

include_directories(${SDL2_INCLUDE_DIR})
add_executable(${PROJECT_NAME} main.cpp
        Game.cpp
        Game.h
        Message.cpp
        Message.h
        GameEngine.cpp
        GameEngine.h
        Player.cpp
        Player.h
)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIB_DIR}/SDL2.lib ${SDL2_LIB_DIR}/SDL2main.lib)
