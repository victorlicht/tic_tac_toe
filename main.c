#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct player {
    char name[32];
    int *score;
    int *rowInput;
    int *columnInput;
    int playerID;
}Player;


int checkWinner(char gameBoard[3][3]) {
    char players[2] = {'X', 'O'};
    for (int player = 0; player < 2; player++) {
        char currentPlayer = players[player];
        // Check wins possibility
        for (int i = 0; i < 3; i++) {
            // Check the rows & columns
            if ((gameBoard[0][i] == currentPlayer && gameBoard[1][i] == currentPlayer && gameBoard[2][i] == currentPlayer)
             || (gameBoard[i][0] == currentPlayer && gameBoard[i][1] == currentPlayer && gameBoard[i][2] == currentPlayer))
                // 1 means the player of 'X' who wins -1 is 'Y'
                return (currentPlayer == 'X') ? 1 : -1;
            // Check diagonals
            if ((gameBoard[0][0] == currentPlayer && gameBoard[1][1] == currentPlayer && gameBoard[2][2] == currentPlayer)
             || (gameBoard[2][0] == currentPlayer && gameBoard[1][1] == currentPlayer && gameBoard[0][2] == currentPlayer))
                // 1 means the player of 'X' who wins -1 is 'Y'
                return (currentPlayer == 'X') ? 1 : -1;
        }
    }
    // No Winner
    return 0;
}

int inputGame(Player player) {
    // Function of getting the right input
    printf("Enter the row number=: ");
    if(scanf("%d", player.rowInput) != 1 || (*player.rowInput != 0 && *player.rowInput != 1 && *player.rowInput != 2)){
        printf("Invalid Input!!");
        return -1;
    }
    printf("Enter the Column number=: ");
    if(scanf("%d", player.columnInput) != 1 || (*player.columnInput != 0 && *player.columnInput != 1 && *player.columnInput != 2)){
        printf("Invalid Input!!");
        return -1;
    }

    return 0;
}
void inputPlayerName(Player player) {
    // Function to get the name of players
    printf("Player %d:\nEnter Your Name=: ", player.playerID);
    scanf("%s", player.name);
}
void playerInformation(Player player) {
    // Function to display the information of the two players.
    printf("Player %d:\n Name=: %s\n", player.playerID, player.name);
    printf("Score=: %d", *player.score);
}
bool theRightInputs(char gameBoard[3][3], Player player) {
    if (gameBoard[*player.rowInput][*player.columnInput] == 'X' || gameBoard[*player.rowInput][*player.columnInput] == 'Y') {
        return false;
    }
    return true;
}
void theBoard(char gameBoard[3][3]) {
    for (int i = 0; i < 3; ++i) {
        printf("[");
        for (int j = 0; j < 3; ++j) {
            if (gameBoard[i][j] == 0) {
                printf(" . ");
            }
            printf("%c ", gameBoard[i][j]);
        }
        printf("]\n");
    }
}


int main() {
    char gameBoard[3][3] = { {0, 0, 0},
                             {0, 0, 0},
                             {0, 0, 0} };
    Player player1;
    Player player2;
    player1.score = (int*)malloc(sizeof(int));
    player2.score = (int*)malloc(sizeof(int));
    player1.rowInput = (int*)malloc(sizeof(int));
    player1.columnInput = (int*)malloc(sizeof(int));
    player2.rowInput = (int*)malloc(sizeof(int));
    player2.columnInput = (int*)malloc(sizeof(int));
    inputPlayerName(player1);
    inputPlayerName(player2);
    player1.playerID = 1;
    player2.playerID = 2;

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
        } else if (i == 8) {
            printf("DRAW!\n");
        }
    }

    playerInformation(player1);
    playerInformation(player2);

    // Free the dynamically allocated memory
    free(player1.score);
    free(player2.score);
    free(player1.rowInput);
    free(player1.columnInput);
    free(player2.rowInput);
    free(player2.columnInput);

    return 0;
}



