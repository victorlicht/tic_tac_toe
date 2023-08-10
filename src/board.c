//
// Created by vic on 8/8/23.
//
#include "stdio.h"
#include "../include/board.h"


void theBoard(char gameBoard[3][3]) {
    for (int i = 0; i < 3; ++i) {
        printf("[");
        for (int j = 0; j < 3; ++j) {
            if (gameBoard[i][j] == 0) {
                printf(".");
            }
            printf("%c ", gameBoard[i][j]);
        }
        printf("]\n");
    }
}

