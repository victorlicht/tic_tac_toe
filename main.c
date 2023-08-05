#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct player {
    char name[32];
    int *score;
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
                // 1 means the player of 'X' who wins 2 is 'Y'
                return (currentPlayer == 'X') ? 1 : 2;
            // Check diagonals
            if ((gameBoard[0][0] == currentPlayer && gameBoard[1][1] == currentPlayer && gameBoard[2][2] == currentPlayer)
             || (gameBoard[2][0] == currentPlayer && gameBoard[1][1] == currentPlayer && gameBoard[0][2] == currentPlayer))
                // 1 means the player of 'X' who wins 2 is 'Y'
                return (currentPlayer == 'X') ? 1 : 2;
        }
    }
    // No Winner
    return 0;
}

void inputGame() {
    int rowInput, columnInput;
    printf("Enter the row number: ");
    if(scanf("%d", &rowInput) != 1 || (rowInput != 0 && rowInput != 1 && rowInput != 2)){
        printf("Invalid Input!!");
    }
    printf("Enter the Column number: ");
    if(scanf("%d", &columnInput) != 1 || (columnInput != 0 && columnInput != 1 && columnInput != 2)){
        printf("Invalid Input!!");
    }
}
void inputPlayerName(Player *player, int playerID) {
    // Function to get the name of players
    printf("Player %d:\nEnter Your Name=: ", playerID);
    scanf("%s", player->name);
}
void playerInformation(Player *player, int playerID) {
    // Function to display the information of the two players.
    printf("Player %d:\n Name=: %s\n", playerID, player->name);
    printf("Score=: %d", *player->score);
}

int main() {
    return 0;
}



