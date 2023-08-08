//
// Created by vic on 8/8/23.
//
#include "stdio.h"
#include "../include/player.h"

void inputPlayerName(Player *player) {
    printf("Player %d:\nEnter Your Name=: ", *player->playerID);
    scanf("%s", player->name);
}
void playerInformation(Player player) {
    printf("Player %d:\nName=: %s\n", *player.playerID, player.name);
    printf("Score=: %d\n", *player.score);
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


