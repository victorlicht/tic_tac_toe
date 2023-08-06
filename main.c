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

int inputGame(Player *player) {
    // Function of getting the right input
    printf("Enter the row number=: ");
    if(scanf("%d", player->rowInput) != 1 || (*player->rowInput != 0 && *player->rowInput != 1 && *player->rowInput != 2)){
        printf("Invalid Input!!");
        return -1;
    }
    printf("Enter the Column number=: ");
    if(scanf("%d", player->columnInput) != 1 || (*player->columnInput != 0 && *player->columnInput != 1 && *player->columnInput != 2)){
        printf("Invalid Input!!");
        return -1;
    }

    return 0;
}
void inputPlayerName(Player *player) {
    // Function to get the name of players
    printf("Player %d:\nEnter Your Name=: ", player->playerID);
    scanf("%s", player->name);
}
void playerInformation(Player *player) {
    // Function to display the information of the two players.
    printf("Player %d:\n Name=: %s\n", player->playerID, player->name);
    printf("Score=: %d", *player->score);
}
bool theRightInputs(char gameBoard[3][3], Player *player) {
    if (gameBoard[*player->rowInput][*player->columnInput] == 'X' || gameBoard[*player->rowInput][*player->columnInput] == 'Y') {
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
void displayTheBoard(char gameBoard[3][3], Player *player) {
    int checkBoardInput;
    bool endGame = false;
    theBoard(gameBoard);
    while (!endGame) {
            do {
                printf("You can just enter the values {0, 1, 2}");
                printf("Now %s Enter Your Move: ", player->name);
                checkBoardInput = inputGame(player);
                if(!theRightInputs(gameBoard, player)) {
                    checkBoardInput = -1;
                    printf("There is an input there IDIOT!!");
                }
            }while (checkBoardInput == 0);
    }
}

int main() {
    char gameBoard[3][3] = { {0, 0, 0},
                             {0, 0, 0},
                             {0, 0, 0} };
    return 0;
}



