#include "leetcode.h"

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
      if (grid.size() == 0) return 0;

      int sum = 0;
      int m = grid.size();
      int n = grid[0].size();
      vector<int> pre(n, 0), cur(n, 0);
      pre[0] = grid[0][0];
      for (int j = 1; j < n; ++j) {
        pre[j] = pre[j-1] + grid[0][j];
      }

      for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (j > 0) {
            cur[j] = grid[i][j] + min(cur[j-1], pre[j]);
          } else {
            cur[j] = grid[i][j] + pre[j];
          }
        }
        pre = cur;
      }
      
      return pre[n-1];
    }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  const int n = 5;
  int A[][n] = {
    {1, 3, 5, 7, 9},
    // {9, 7, 5, 3, 1},
    {5, 4, 7, 1, 3},
    // {6, 1, 2, 4, 6},
    // {0, 0, 4, 7, 8},
    // {9, 7, 5, 3, 1},
  };

  int m = sizeof(A) / sizeof(int [n]);
  vector<vector<int> > grid(m);
  for (int i = 0; i < m; ++i) {
    grid[i].assign(A[i], A[i] + n);
  }
  for (auto row : grid) {
    for (auto val : row) {
      cout << val << ' ';
    }
    cout << '\n';
  }
  cout << sol.minPathSum(grid) << endl;
  return 0;
}