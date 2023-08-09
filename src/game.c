//
// Created by vic on 8/8/23.
//
#include "stdio.h"
#include "../include/game.h"

int checkWinner(char gameBoard[3][3]) {
    char players[2] = {'X', 'O'};
    for (int player = 0; player < 2; player++) {
        char currentPlayer = players[player];
        for (int i = 0; i < 3; i++) {
            // Check the rows & columns
            if ((gameBoard[0][i] == currentPlayer && gameBoard[1][i] == currentPlayer && gameBoard[2][i] == currentPlayer)
                || (gameBoard[i][0] == currentPlayer && gameBoard[i][1] == currentPlayer && gameBoard[i][2] == currentPlayer))
                return (currentPlayer == 'X') ? 1 : -1;
            // Check diagonals
            if ((gameBoard[0][0] == currentPlayer && gameBoard[1][1] == currentPlayer && gameBoard[2][2] == currentPlayer)
                || (gameBoard[2][0] == currentPlayer && gameBoard[1][1] == currentPlayer && gameBoard[0][2] == currentPlayer))
                return (currentPlayer == 'X') ? 1 : -1;
        }
    }
    return 0;
}

int inputGame(Player player) {
    printf("\nEnter the row number=: ");
    if(scanf("%d", player.rowInput) != 1 || (*player.rowInput != 0 && *player.rowInput != 1 && *player.rowInput != 2)){
        printf("Invalid Input!!\n");
        return -1;
    }
    printf("\nEnter the Column number=: ");
    if(scanf("%d", player.columnInput) != 1 || (*player.columnInput != 0 && *player.columnInput != 1 && *player.columnInput != 2)){
        printf("Invalid Input!!\n");
        return -1;
    }

    return 0;
}

bool theRightInputs(char gameBoard[3][3], Player player) {
    if (gameBoard[*player.rowInput][*player.columnInput] == 'X' || gameBoard[*player.rowInput][*player.columnInput] == 'O') {
        return false;
    }
    return true;
}

