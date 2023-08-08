#include <stdio.h>

#include "../include/player.h"
#include "../include/game.h"
#include "../include/board.h"

int main() {
    char gameBoard[3][3] = { {0, 0, 0},
                             {0, 0, 0},
                             {0, 0, 0} };
    Player player1;
    Player player2;
    prepareData(&player1, 1);
    prepareData(&player2, 2);
    for (int i = 0; i < 9; ++i) {
        if (i % 2 == 0) {
            int checkBoardInput;
            theBoard(gameBoard);
            do {
                printf("You can just enter the values {0, 1, 2}");
                printf("Now %s Enter Your Move: ", player1.name);
                checkBoardInput = inputGame(player1);
                if (!theRightInputs(gameBoard, player1)) {
                    checkBoardInput = -1;
                    printf("There is an input there IDIOT!!\n");
                }
            } while (checkBoardInput == -1);

            // Update the game board with the player's move
            gameBoard[*player1.rowInput][*player1.columnInput] = 'X';
        } else {
            int checkBoardInput;
            theBoard(gameBoard);
            do {
                printf("You can just enter the values {0, 1, 2}");
                printf("Now %s Enter Your Move: ", player2.name);
                checkBoardInput = inputGame(player2);
                if (!theRightInputs(gameBoard, player2)) {
                    checkBoardInput = -1;
                    printf("There is an input there IDIOT!!\n");
                }
            } while (checkBoardInput == -1);

            // Update the game board with the player's move
            gameBoard[*player2.rowInput][*player2.columnInput] = 'O';
        }
        int result = checkWinner(gameBoard);
        if (result == 1) {
            printf("The player %s WIN :)\n", player1.name);
            *player1.score += 1;
            break;
        } else if (result == -1) {
            printf("The player %s WIN :)\n", player2.name);
            *player2.score += 1;
            break;
        } else if (result == 0) {
            printf("DRAW!\n");
        }
    }
    playerInformation(player1);
    playerInformation(player2);
    freeData(player1);
    freeData(player2);
    return 0;
}



