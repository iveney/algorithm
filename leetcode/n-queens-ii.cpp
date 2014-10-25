// one obvious opt is symmetry
#include "leetcode.h"

class Solution2 {
public:
  int count;
  int N;
  int totalNQueens(int n) {
    N = n;
    count = 0;
    vector<vector<bool>> board(n, vector<bool>(n, false));
    search(board, n);
    return count;
  }

  bool valid(vector<vector<bool>> &board, int i, int j) {
    for (int k = 1; k <= i; ++k) {
      if (board[i-k][j] ||
          (j-k >= 0 && board[i-k][j-k]) ||
          (j+k < N && board[i-k][j+k]))
        return false;
    }
    return true;
  }

  void search(vector<vector<bool>> &board, int n) {
    if (n == 0) {
      ++count;
      return;
    }

    int level = N - n;
    for (int j = 0; j < N; ++j) {
      if (valid(board, level, j)) {
        board[level][j] = true;
        search(board, n - 1);
        board[level][j] = false;
      }
    }
  }
};

class Solution {
  vector<vector<string> > sol;
  vector<string> grid;
  int N;
public:
    int totalNQueens(int n) {
      solveNQueens(n);
      return sol.size();
    }

    vector<vector<string> > solveNQueens(int n) {
      N = n;
      string line(n, '.');
      grid.assign(n, line);

      solve(0);

      return sol;
    }

    bool is_avail(int r, int c) {
      for (int i = 1; i <= r; i++) {
        if (grid[r-i][c] == 'Q' ||
           (c - i >= 0 && grid[r-i][c-i] == 'Q') ||
           (c + i < N && grid[r-i][c+i] == 'Q'))
          return false;
      }

      return true;
    }

    void solve(int depth) {
      if (depth >= N) return;

      for (int j = 0; j < N; ++j) {
        // detect if available

        if (is_avail(depth, j)) {
          grid[depth][j] = 'Q';

          // output solution
          if (depth == N-1) {
            sol.push_back(grid);
          } else {
            solve(depth+1);
          }

          // reset
          grid[depth][j] = '.';
        }
      }
    }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  auto result = sol.solveNQueens(8);
  cout << result.size() << endl;
  for (auto s : result) {
    for (auto l : s) {
      cout << l << '\n';
    }
    cout << endl;
  }
  return 0;
}