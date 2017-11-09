cmake_minimum_required(VERSION 2.6)
project(game_of_lifesdl)

add_executable(game_of_lifesdl main.cpp)

install(TARGETS game_of_lifesdl RUNTIME DESTINATION bin)
