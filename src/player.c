//
// Created by vic on 8/8/23.
//
#include "stdio.h"
#include "../include/player.h"
#include "string.h"

void inputPlayerName(Player *player) {
    printf("Player %d:\nEnter Your Name=: ", *player->playerID);
    scanf("%s", player->name);
}
void playerInformation(Player player) {
    printf("Player %d=: { Name=: %s, Score=: %d };\n", *player.playerID, player.name, *player.score);
}
void prepareRobotData(Player *player, int ID) {
    player->score = (int*)malloc(sizeof(int));
    player->rowInput = (int*)malloc(sizeof(int));
    player->columnInput = (int*)malloc(sizeof(int));
    player->playerID = (int*)malloc(sizeof(int));
    *player->playerID = ID;
    strcpy(player->name, "Robot");
}
void prepareData(Player *player, int ID) {
    player->score = (int*)malloc(sizeof(int));
    player->rowInput = (int*)malloc(sizeof(int));
    player->columnInput = (int*)malloc(sizeof(int));
    player->playerID = (int*)malloc(sizeof(int));
    *player->playerID = ID;
    inputPlayerName(player);
}

void freeData(Player player) {
    free(player.score);
    free(player.rowInput);
    free(player.columnInput);
    free(player.playerID);
}


