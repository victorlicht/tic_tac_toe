//
// Created by vic on 8/8/23.
//
#include "stdlib.h"

#ifndef TIC_TAC_TOE_PLAYER_H
#define TIC_TAC_TOE_PLAYER_H

typedef struct player {
    char name[32];
    int *score;
    int *rowInput;
    int *columnInput;
    int *playerID;
}Player;

void inputPlayerName(Player *player);
void playerInformation(Player player);
void prepareRobotData(Player *player, int ID);
void prepareData(Player *player, int ID);
void freeData(Player player);
#endif //TIC_TAC_TOE_PLAYER_H
