#include <stdio.h>

#include "../include/player.h"
#include "../include/game.h"
#include "../include/board.h"

int main() {
    menu:
    printf("---------------------------------\n");
    printf("|        Hello to Tic Tac Toe    |\n");
    printf("---------------------------------\n\n");

    printf("Welcome to the classic game of Tic Tac Toe!\nTest your tactical skills and strategic thinking in this battle of X's and O's.\nChoose your mode and let the games begin:\n\n");

    printf("1. Play\n");
    printf("0. Exit\n\n");

    printf("Enter the corresponding number to choose your preferred mode or to exit the game.\n");
    printf("Option:= ");
    int option;
    scanf("%d", &option);
    switch (option) {
        case 1:
            printf("===========================\n");
            Player player1;
            Player player2;
            prepareData(&player1, 1);
            prepareData(&player2, 2);
            while(true) {
                char gameBoard[3][3] = { {0, 0, 0},
                                         {0, 0, 0},
                                         {0, 0, 0} };
                for (int i = 0; i < 9; i++) {
                    if (i % 2 == 0) {
                        int checkBoardInput;
                        theBoard(gameBoard);
                        do {
                            printf("You can just enter the values {0, 1, 2}\n");
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
                            printf("You can just enter the values {0, 1, 2}\n");
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
                    } else if (result == 0 && i == 8) {
                        printf("DRAW!\n");
                    }
                }
                playerInformation(player1);
                playerInformation(player2);
                printf("Choose Option\n");
                printf("1. restart the game\n");
                printf("2. Go to menu\n");
                printf("0. exit");
                int option2;
                scanf("%d", &option2);
                switch (option2) {
                    case 1:
                        continue;
                    case 2:
                        goto menu;
                    case 0:
                        freeData(player1);
                        freeData(player2);
                        exit(0);
                    default:
                        printf("Sorry Wrong Input\n Power Off Automatically");
                        freeData(player1);
                        freeData(player2);
                        exit(0);
                }
            }
        case 0:
            exit(0);
        default:
            printf("Sorry Wrong Input\n Power Off Automatically");
            exit(0);
    }
}



