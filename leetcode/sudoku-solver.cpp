#include <bitset>
#include "leetcode.h"
#include "array2D.hpp"

class Solution {
  int count = 0;
  vector<bitset<9> > row;
  vector<bitset<9> > col;
  vector<vector<bitset<9> > > grid;
public:
  void solveSudoku(vector<vector<char> > &board) {
    // initialize the bitsets
    row.resize(9);
    col.resize(9);
    grid.assign(3, vector<bitset<9> >(3));
    count = 0;
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] == '.') {
          ++count;
          continue;
        }
        int k = board[i][j] - '1';
        row[i][k] = 1;
        col[j][k] = 1;
        grid[i/3][j/3][k] = 1;
      }
    }
    // cout << "count = " << count << endl;
    solve(board);
    // print
  }

  bool solve(vector<vector<char> > &board) {
    if (count == 0) return true;
    if (count % 5 == 0) print_2D<char> (board);
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] != '.') 
          continue;
        // try to fill a feasible number into empty slot
        for (int k = 0; k < 9; ++k) {
          int r = i/3, c = j/3;
          if (!row[i][k] && !col[j][k] && !grid[r][c][k]) {
            board[i][j] = k + '1';
            row[i][k] = col[j][k] = grid[r][c][k] = 1;
            --count;
            if ( solve(board) ) return true;
            ++count;
            row[i][k] = col[j][k] = grid[r][c][k] = 0;
            board[i][j] = '.';
          }
        } // for k
      } // for j
    } // for i
    return false;
  }
};

int main() {
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

  print_2D<char>(board);
  sol.solveSudoku(board);
  print_2D<char>(board);
  
  return 0;
}