/*
 * Created by vic
 */
#include <stdio.h>
#include "stdbool.h"
#include "../include/player.h"
#include "../include/game.h"
#include "../include/board.h"
#include "../include/robot.h"

int main() {
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
    while (true) {
        if (scanf("%d", &option) != 1)
            printf("Invalid Input!!");
        else break;
    }
    bool restart = true;
    Player firstPlayer, secondPlayer, currentPlayer, robotPlayer;
    switch (option) {
        case 1:
            while (true) {
                printf("Choose with who you play\n");
                printf("1. Friend\n");
                printf("2. Computer\n");
                printf("0. Exit\n");
                int innerOption;
                while (true) {
                    if (scanf("%d", &innerOption) != 1)
                        printf("Invalid Input!!");
                    else break;
                }
                switch (innerOption) {
                    case 1:
                        prepareData(&firstPlayer, 1);
                        prepareData(&secondPlayer, 2);
                        while(true) {
                            //Initialization the board
                            char gameBoard[3][3] = { {0, 0, 0},
                                                     {0, 0, 0},
                                                     {0, 0, 0} };
                            for (int i = 0; i < 9; i++) {
                                if (i % 2 == 0) currentPlayer = firstPlayer;
                                else currentPlayer = secondPlayer;
                                system("clear");
                                theBoard(gameBoard);
                                play(gameBoard, currentPlayer);
                                // Update the game board with the player's move
                                gameBoard[*currentPlayer.rowInput][*currentPlayer.columnInput] = (i % 2 == 0) ? 'X' : 'O';
                                int result  = winResult(gameBoard, currentPlayer, i);
                                if (result != 99) break;
                            }
                            playerInformation(firstPlayer);
                            playerInformation(secondPlayer);
                            printf("Choose Option\n");
                            printf("1. Restart the game\n");
                            printf("2. Go to menu\n");
                            printf("0. Exit");
                            int lastOption;
                            while (true) {
                                if (scanf("%d", &lastOption) != 1)
                                    printf("Invalid Input!!");
                                else break;
                            }
                            switch (lastOption) {
                                case 1:
                                    continue;
                                case 2:
                                    break;
                                case 0:
                                    exit(0);
                                default:
                                    printf("Invalid Input Turn Off Automatically");
                                    exit(0);
                            }
                            break;
                        }
                    case 2:
                        printf("Soon..");
                        break;
                    case 0:
                        freeData(firstPlayer);
                        freeData(secondPlayer);
                        exit(0);
                    default:
                        printf("Invalid Input Turn Off Automatically");
                        exit(0);
                }
            }
        case 0:
            exit(0);
        default:
            printf("Invalid Input Turn Off Automatically");
            exit(0);
    }
}