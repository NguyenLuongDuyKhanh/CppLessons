// C++ program to solve a Sudoku puzzle using the
// Cross-Hatching with Backtracking approach

#include <iostream>
#include <vector>

#define N 9

using namespace std;

// Function to print the board
void printBoard(const vector<vector<int> >& board)
{
    // Iterate over each row of the board
    for (int r = 0; r < N; r++) {
        // Iterate over each column of the board
        for (int d = 0; d < N; d++) {
            // Print each cell
            cout << board[r][d] << " ";
        }
        // New line after each row
        cout << endl;
    }
}

// Function to check if it is safe to place a number in the
// cell
bool isSafe(const vector<vector<int> >& board, int row,
            int col, int num)
{
    // Check the row, column, and 3x3 subgrid for the number
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num || board[x][col] == num
            || board[row - row % 3 + x / 3]
                    [col - col % 3 + x % 3]
                   == num) {
            // Number already present in row, column, or
            // subgrid
            return false;
        }
    }
    // Safe to place the number
    return true;
}

// Function to apply cross-hatching technique
bool applyCrossHatching(vector<vector<int> >& board)
{
    // Flag to check if any updates were made
    bool updated = false;

    // Iterate over each number from 1 to 9
    for (int num = 1; num <= 9; num++) {
        // Check each row for potential placements
        for (int row = 0; row < N; row++) {
            int count = 0, colIndex = -1;

            // Find columns in the row where the number can
            // be placed
            for (int col = 0; col < N; col++) {
                if (board[row][col] == 0
                    && isSafe(board, row, col, num)) {
                    count++;
                    colIndex = col;
                }
            }
            // Place the number if it is the only valid
            // option in the row
            if (count == 1) {
                board[row][colIndex] = num;
                updated = true;
            }
        }

        // Check each column for potential placements
        for (int col = 0; col < N; col++) {
            int count = 0, rowIndex = -1;

            // Find rows in the column where the number can
            // be placed
            for (int row = 0; row < N; row++) {
                if (board[row][col] == 0
                    && isSafe(board, row, col, num)) {
                    count++;
                    rowIndex = row;
                }
            }
            // Place the number if it is the only valid
            // option in the column
            if (count == 1) {
                board[rowIndex][col] = num;
                updated = true;
            }
        }
    }
    // Return if any updates were made
    return updated;
}

// Function to solve the Sudoku using Cross-Hatching with
// Backtracking approach
bool solveSudokuCrossHatching(vector<vector<int> >& board)
{
    // Apply cross-hatching until no more updates can be
    // made
    while (applyCrossHatching(board))
        ;

    int row = -1;
    int col = -1;
    bool isEmpty = true;

    // Find the first empty cell
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }

    // If no empty cells are found, the board is solved
    if (isEmpty) {
        return true;
    }

    // Try placing numbers from 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        // Check if the number can be placed in the cell
        if (isSafe(board, row, col, num)) {
            // Place the number
            board[row][col] = num;

            // Recursively attempt to solve the rest of the
            // board
            if (solveSudokuCrossHatching(board)) {
                return true; // If a solution is found,
                             // return true
            }

            // If placing num does not lead to a solution,
            // undo the placement (backtrack)
            board[row][col] = 0;
        }
    }
    // No solution found
    return false;
}

int main()
{
    // Initial Sudoku board with some cells filled
    vector<vector<int> > board
        = { { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
            { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
            { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
            { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
            { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
            { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
            { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
            { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
            { 0, 0, 0, 0, 8, 0, 0, 7, 9 } };

    // Solve the Sudoku and print the result
    if (solveSudokuCrossHatching(board)) {
        // Print the solved board
        printBoard(board);
    }
    else {
        // No solution found
        cout << "No solution exists" << endl;
    }

    return 0;
}