#include "leetcode.h"
#include "array2D.hpp"

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
      return validRowCol(board, 0) && validRowCol(board, 1) &&
             validBlock(board);
    }

    bool validRowCol(vector<vector<char> > &board, int check_row) {
      vector<int> bits;
      for (int i = 0; i < 9; i++) {
        bits.assign(10, 0);
        for (int j = 0; j < 9; j++) {
          char c = check_row ? board[i][j] : board[j][i];
          if (c == '.')
            continue;

          c -= '0';
          if (bits[c] == 1)
            return false;
          bits[c] = 1;
        }
      }
      return true;
    }

    bool validBlock(vector<vector<char> > &board) {
      vector<int> bits;
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          bits.assign(10, 0);
          for (int k = 0; k < 3; ++k) {
            for (int l = 0; l < 3; ++l) {
              char c = board[i*3+k][j*3+l];
              if (c == '.')
                continue;

              c -= '0';
              if (bits[c] == 1)
                return false;
              bits[c] = 1;
            }
          }
        }
      } // for i

      return true;
    }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  char b[9][10] = {
    "53..7....",
    "6..195...",
    ".98....6.",
    "8...6...3",
    "4..8.3..1",
    "7...2...6",
    ".6....28.",
    "...419..5",
    "....8..79",
  };
  Array2D<char>::type board = fromCArray((char*)b, 9, 10);
  // remove the NULL char
  for (auto &row : board)
    row.resize(9);

  cout << sol.isValidSudoku(board) << endl;

  board[2][8] = '8'; // screw up row
  cout << sol.isValidSudoku(board) << endl;
  board[2][8] = '.';

  board[8][1] = '3'; // screw up col
  cout << sol.isValidSudoku(board) << endl;
  board[8][1] = '.'; // screw up col

  board[3][3] = '2'; // screw up block
  cout << sol.isValidSudoku(board) << endl;

  return 0;
}