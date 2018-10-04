cmake_minimum_required(VERSION 2.6)
project(game_of_lifesdl)

include_directories("/usr/include/SDL2")

add_executable(gameoflife src/main.cpp src/board.cpp)

target_link_libraries(gameoflife SDL2 SDL2_image)
