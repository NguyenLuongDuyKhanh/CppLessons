#include <iostream>
#include <vector>

#define LEN 9 // LEN represents the size of our sudoku

// the board is passed by reference (&)
bool is_possible(std::vector<std::vector<int>>& board,int row,int col, int val)
{
    // check if the column is valid
    for (int i=0;i<LEN;i++)
    {
        if (board[i][col] == val)
        {
            return false;
        }
    }
    // check if the row is valid
    for (int i=0;i<LEN;i++)
    {
        if (board[row][i] == val)
        {
            return false;
        }
    }
    // check if the 3x3 square is valid
    int startRow = 3*(row/3); //get if it is the 0,1 or 2 3x3 square then *3
    int startCol = 3*(col/3);

    /* alternative way
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    */
   
    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (board[i][j] == val)
            {
                return false;
            }
        }
    }
    // if every test passed
    return true;
}

bool solve(std::vector<std::vector<int>>& board,int row,int col)
{

  if (col == LEN)
  {
    if (row == LEN-1)
    {
      return true; // we have filled the last square 
                  // and add 1 to col (sudoku solved)
    }
    // we are at the end of a column
      col = 0;
      row ++;
   }

    if (board[row][col] != 0) // Already filled, solve for next square
    {
        return solve(board,row,col+1);
    }

    for (int x = 1; x <= LEN; x++) //try every value between 1 and 9
    { 
      if (is_possible(board, row, col, x))
      {
        board[row][col] = x;
        if (solve(board, row, col + 1)) // try x and check if it works
        {
          return true;
        }
           
       }
        board[row][col] = 0; // previous x value didn't work
                             // reset and try another x
    }
  
    return false; // We are in a dead end
                  // can't solve the sudoku with current values
}

  void print_board(const std::vector<std::vector<int>>& board) {
      for (int row = 0; row < LEN; ++row) {
          for (int col = 0; col < LEN; ++col) {
              std::cout << board[row][col] << " ";
              if ((col + 1) % 3 == 0 && col < LEN - 1) {
                  std::cout << "| ";
              }
          }
          std::cout << std::endl;
          if ((row + 1) % 3 == 0 && row < LEN - 1) {
              std::cout << "------+-------+------" << std::endl;
          }
      }
  }
  
  int main() {
      std::vector<std::vector<int>> sudokuBoard = {
          {5, 3, 0, 0, 7, 0, 0, 0, 0},
          {6, 0, 0, 1, 9, 5, 0, 0, 0},
          {0, 9, 8, 0, 0, 0, 0, 6, 0},
          {8, 0, 0, 0, 6, 0, 0, 0, 3},
          {4, 0, 0, 8, 0, 3, 0, 0, 1},
          {7, 0, 0, 0, 2, 0, 0, 0, 6},
          {0, 6, 0, 0, 0, 0, 2, 8, 0},
          {0, 0, 0, 4, 1, 9, 0, 0, 5},
          {0, 0, 0, 0, 8, 0, 0, 7, 9}
      };
  
      std::cout << "Sudoku Grid:" << std::endl;
      print_board(sudokuBoard);
  
      bool solved = solve(sudokuBoard, 0, 0);
      
      if (solved) {
          std::cout << "\nSolved Sudoku:" << std::endl;
          print_board(sudokuBoard);
      } else {
          std::cout << "\nNo solution exists." << std::endl;
      }
  
      return 0;
}
