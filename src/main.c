#include <stdio.h>
#include "../include/player.h"
#include "../include/game.h"
#include "../include/board.h"
#include "../include/robot.h"
int main() {
    menu:
    printf("---------------------------------\n");
    printf("|        Hello to Tic Tac Toe    |\n");
    printf("---------------------------------\n\n");

    printf("Welcome to the classic game of Tic Tac Toe!\n"
           "Test your tactical skills and strategic thinking in this battle of X's and O's.\n"
           "Choose your mode and let the games begin:\n\n");

    printf("1. Play\n");
    printf("0. Exit\n\n");

    printf("Enter the corresponding number to choose your preferred mode or to exit the game.\n");
    printf("Option:= ");
    int option;
    scanf("%d", &option);
    system("clear");
    printf("===========================\n");
    Player player1;
    Player player2;
    Player currentPlayer;
    Player robot;
    prepareData(&player1, 1);
    prepareData(&player2, 2);
    prepareData(&robot, 3);
    switch (option) {
        case 1:
            while(true) {
                char gameBoard[3][3] = { {0, 0, 0},
                                         {0, 0, 0},
                                         {0, 0, 0} };
                for (int i = 0; i < 9; i++) {
                    if (i % 2 == 0) currentPlayer = player1;
                    else currentPlayer = player2;
                    system("clear");
                    theBoard(gameBoard);

                    play(gameBoard, currentPlayer);
                    // Update the game board with the player's move

                    gameBoard[*currentPlayer.rowInput][*currentPlayer.columnInput] = (i % 2 == 0) ? 'X' : 'O';
                    int result  = winResult(gameBoard, currentPlayer, i);
                    printf("Result %d Row Input %d Column Input %d\n", playerAI(gameBoard, 8, NULL, robot), *robot.rowInput, *robot.columnInput);
                    if (result != 99) break;
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
            while(true) {
                char gameBoard[3][3] = { {0, 0, 0},
                                         {0, 0, 0},
                                         {0, 0, 0} };
                for (int i = 0; i < 9; i++) {
                    if (i % 2 == 0) currentPlayer = player1;
                    else currentPlayer = robot;
                    system("clear");
                    theBoard(gameBoard);
                    int checkBoardInput;
                    do {
                        printf("=======================================\n");
                        printf("You can just enter the values {0, 1, 2}\n");
                        printf("Now %s Enter Your Move:\n", currentPlayer.name);
                        if (i % 2 == 0){
                        checkBoardInput = inputGame(currentPlayer);}
                    } while (checkBoardInput == -1);

                    // Update the game board with the player's move
                    gameBoard[*currentPlayer.rowInput][*currentPlayer.columnInput] = (i % 2 == 0) ? 'X' : 'O';
                    int result  = winResult(gameBoard, currentPlayer, i);
                    if (result != 99) break;
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
        default:
            printf("Sorry Wrong Input\nPower Off Automatically...");
            exit(0);
    }
}



