#include <iostream>
using namespace std;

#define N 8 // You can change this for different sizes of the chessboard

// Function to print the solution board
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if a queen can be placed at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check the column
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Function to solve the N-Queen problem using backtracking
bool solveNQueen(int board[N][N], int row) {
    if (row == N) {
        printBoard(board); // Print solution when all queens are placed
        return true;
    }

    bool foundSolution = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1; // Place the queen
            foundSolution = solveNQueen(board, row + 1) || foundSolution;
            board[row][col] = 0; // Backtrack
        }
    }
    return foundSolution;
}

int main() {
    int board[N][N] = {0}; // Initialize the board with all 0s

    if (!solveNQueen(board, 0))
        cout << "No solution exists for " << N << " queens." << endl;

    return 0;
}
