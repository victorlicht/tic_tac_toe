//
// Created by vic on 8/10/23.
//
#include "../include/game.h"
#include "../include/player.h"
#include "stdbool.h"
#include "stdio.h"
int playerAI(char gameBoard[3][3], int depth, bool isMaximizing, Player robot, bool firstTime) {
    int result = checkWinner(gameBoard);
    if (depth == 0 || result != 0) {
        return result;
    }
    if (isMaximizing) {
        int finalScore = -10;
        int i, j,  ii, jj;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (gameBoard[i][j] == 0) {
                    gameBoard[i][j] = 'X';
                    int score = playerAI(gameBoard, depth - 1, false, robot, false);
                    gameBoard[i][j] = 0;
                    if (finalScore < score) {
                        finalScore = score;
                        ii = i;
                        jj = j;

                    }
                    if(firstTime) {
                        printf("i: %d j: %d, %d\n", i, j, score);

                    }
                }

            }
        }
        *robot.columnInput = jj;
        *robot.rowInput = ii;
        return finalScore;
    }else {
        int finalScore = 10;
        int i, j;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (gameBoard[i][j] == 0) {
                    gameBoard[i][j] = 'O';
                    int score = playerAI(gameBoard, depth - 1, true, robot, false);
                    gameBoard[i][j] = 0;
                    if (finalScore > score) {
                        finalScore = score;

                    }
                    if(firstTime) {
                        printf("i: %d j: %d, %d\n", i, j, score);

                    }
                }

            }
        }
        return finalScore;
    }
}
