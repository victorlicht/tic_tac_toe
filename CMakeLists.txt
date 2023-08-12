cmake_minimum_required(VERSION 3.25)
project(tic_tac_toe C)

set(CMAKE_C_STANDARD 23)

add_executable(tic_tac_toe src/main.c include/player.h include/game.h include/board.h src/board.c src/player.c src/game.c src/robot.c include/robot.h)


