#include "leetcode.h"
#include "array2D.hpp"

// #include <bitset>
// using std::bitset;
// leetcode does not support bitset

class Bitset {
public:
  Bitset(int n = 9) {bits.resize(n);}
  int count() const {return std::count(bits.begin(), bits.end(), 1);}
  vector<bool>::reference operator [] (int k) {return bits[k];}
  vector<bool> bits;
};

class Solution {
  int count = 0;            // how many cells remaining
  vector<Bitset> row;
  vector<Bitset> col;
  vector<vector<Bitset> > grid;
public:
  void solveSudoku(vector<vector<char> > &board) {
    // initialize the bitsets
    row.resize(9);
    col.resize(9);
    grid.assign(3, vector<Bitset>(3));
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
    solve(board);
  }

  std::pair<int, int> search_cell(vector<vector<char> > &board) {
    int min = 27, r = -1, c = -1;
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] != '.') continue;

        int total = 24 - (row[i].count() + col[j].count() + grid[i/3][j/3].count());
        // printf("filling %d, %d = %d\n", i, j, total);
        if (total < min) {
          r = i;
          c = j;
          min = total;
        }
      }
    }

    // int dummy;
    // cin >> dummy;
    return make_pair(r, c);
  }

  bool solve(vector<vector<char> > &board) {
    // if (count % 5 == 0) print_2D<char> (board);
    if (count == 0) return true;
    // search for a cell that is likely to complete a row/col/block
    int i, j;
    std::tie(i, j) = search_cell(board);

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