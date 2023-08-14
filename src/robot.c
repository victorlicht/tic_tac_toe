//
// Created by vic on 8/10/23.
//
#include "../include/game.h"
#include "../include/player.h"
#include "stdbool.h"
#include "stdio.h"
int playerAI(char gameBoard[3][3], int depth, int alpha, int beta, bool isMaximizing, Player robot) {
    int result = checkWinner(gameBoard);
    if (depth == 0 || result != 0) {
        return result;
    }

    if (isMaximizing) {
        int maxScore = -10;
        int ii, jj;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (gameBoard[i][j] == 0) {
                    gameBoard[i][j] = 'X';
                    int score = playerAI(gameBoard, depth - 1, alpha, beta, false, robot);
                    gameBoard[i][j] = 0;
                    if (score > maxScore) {
                        maxScore = score;
                        ii = i;
                        jj = j;
                    }
                    alpha = (alpha > score) ? alpha : score;
                    if (beta <= alpha) {
                        break; // Beta cutoff
                    }
                }
            }
        }
        *robot.rowInput = ii;
        *robot.columnInput = jj;
        return maxScore;
    } else {
        int minScore = 10;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (gameBoard[i][j] == 0) {
                    gameBoard[i][j] = 'O';
                    int score = playerAI(gameBoard, depth - 1, alpha, beta, true, robot);
                    gameBoard[i][j] = 0;
                    if (score < minScore) {
                        minScore = score;
                    }
                    beta = (beta < score) ? beta : score;
                    if (beta <= alpha) {
                        break; // Alpha cutoff
                    }
                }
            }
        }
        return minScore;
    }
}
