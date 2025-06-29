#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;
    int movesCount;

    void initializeBoard() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
    }

    void displayBoard() const {
        cout << "\n  0   1   2\n";
        for (int i = 0; i < 3; ++i) {
            cout << i << " ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << endl;
            if (i < 2) cout << "  ---------\n";
        }
        cout << endl;
    }

    bool isValidMove(int row, int col) const {
        return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
    }

    bool checkWin() const {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) 
                return true;
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) 
                return true;
        }
        // Check diagonals
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
            return true;
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) 
            return true;
        return false;
    }

    bool isDraw() const {
        return movesCount == 9;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

public:
    TicTacToe() : currentPlayer('X'), movesCount(0) {
        initializeBoard();
    }

    void startGame() {
        bool playAgain = true;
        while (playAgain) {
            movesCount = 0;
            initializeBoard();
            currentPlayer = 'X';
            bool gameEnded = false;

            while (!gameEnded) {
                displayBoard();
                int row, col;
                cout << "Player " << currentPlayer << ", enter your move (row column): ";
                
                // Input validation
                while (!(cin >> row >> col) || !isValidMove(row, col)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid move! Try again (row column): ";
                }

                board[row][col] = currentPlayer;
                movesCount++;

                if (checkWin()) {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!\n";
                    gameEnded = true;
                } else if (isDraw()) {
                    displayBoard();
                    cout << "It's a draw!\n";
                    gameEnded = true;
                } else {
                    switchPlayer();
                }
            }

            char choice;
            cout << "Play again? (y/n): ";
            cin >> choice;
            playAgain = (choice == 'y' || choice == 'Y');
        }
        cout << "Thanks for playing!\n";
    }
};

int main() {
    TicTacToe game;
    game.startGame();
    return 0;
}