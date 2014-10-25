#include "leetcode.h"

class Solution {
public:
  int uniquePaths(int m, int n) {
    if (m <= 0 || n <= 0) return 0;
    vector<vector<int>> D(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i == 1 && j == 1) {
          D[i][j] = 1;
          continue;
        } 
        D[i][j] = D[i-1][j] + D[i][j-1];
      }
    }
    return D[m][n];
  }
};

class Solution {
int array[105][105];
public:
    int uniquePaths(int m, int n) {
      array[0][0] = 1;
      for (int i = 0; i < m; ++i)
      {
        for (int j = 0; j < n; ++j) {
          if (i - 1 >= 0)
            array[i][j] += array[i-1][j]; 
          if (j - 1 >= 0)
            array[i][j] += array[i][j-1];
        }
      } // for

      return array[m-1][n-1];
    }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  int m = 3, n = 3;
  cout << sol.uniquePaths(m, n) << '\n';
  return 0;
}