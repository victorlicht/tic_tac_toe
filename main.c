#include <stdio.h>
#include <stdbool.h>
struct player {
    char name[32];
    int score;
};
int main() {

}

int checkWinner(char gameBoard[3][3]) {
    char players[2] = {'X', 'O'};
    for (int player = 0; player < 2; player++) {
        char currentPlayer = players[player];
        // Check wins possibility
        for (int i = 0; i < 3; i++) {
            // Check the rows & columns
            if ((gameBoard[0][i] == currentPlayer && gameBoard[1][i] == currentPlayer && gameBoard[2][i] == currentPlayer)
             || (gameBoard[i][0] == currentPlayer && gameBoard[i][1] == currentPlayer && gameBoard[i][2] == currentPlayer))
                return (currentPlayer == 'X') ? 1 : 2;
            // Check diagonals
            if ((gameBoard[0][0] == currentPlayer && gameBoard[1][1] == currentPlayer && gameBoard[2][2] == currentPlayer)
             || (gameBoard[2][0] == currentPlayer && gameBoard[1][1] == currentPlayer && gameBoard[0][2] == currentPlayer))
                return (currentPlayer == 'X') ? 1 : 2;
        }
    }
    return 0;
}

void inputGame() {
    int rowInput[1];
    int columnInput[1];
    int num[2];
    printf("Enter the row number: ");
    fgets(rowInput, sizeof(rowInput), stdin);

    }
}


