#include <iostream>
#include <limits> // for cin.ignore
using namespace std;

char board[3][3];
char player = 'X';

// Function to reset the board
void resetBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = num++;
}

// Function to display the current board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Function to switch player
void switchPlayer() {
    player = (player == 'X') ? 'O' : 'X';
}

// Function to check for a win
bool checkWin() {
    for (int i = 0; i < 3; i++) {
        // Rows and columns
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }
    // Diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

// Function to check for a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

int main() {
    char again;

    do {
        resetBoard();
        player = 'X';
        bool gameOver = false;

        while (!gameOver) {
            displayBoard();
            int move;

            cout << "Player " << player << ", enter a number (1-9): ";
            
            // Input validation
            if (!(cin >> move)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number between 1 and 9.\n";
                continue;
            }

            if (move < 1 || move > 9) {
                cout << "Invalid number! Please choose between 1 and 9.\n";
                continue;
            }

            int row = (move - 1) / 3;
            int col = (move - 1) % 3;

            if (board[row][col] == 'X' || board[row][col] == 'O') {
                cout << "Cell already taken! Try a different one.\n";
                continue;
            }

            board[row][col] = player;

            if (checkWin()) {
                displayBoard();
                cout << "Player " << player << " wins!\n";
                gameOver = true;
            } else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }


    } while (again == 'y' || again == 'Y');

    cout << "Thanks for playing";
    return 0;
}