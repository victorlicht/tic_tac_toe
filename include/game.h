//
// Created by vic on 8/8/23.
//
#include "player.h"
#include "stdbool.h"
#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H

bool theRightInputs(char gameBoard[3][3], Player player);
int checkWinner(char gameBoard[3][3]);
int inputGame(Player player);
#endif //TIC_TAC_TOE_GAME_H
