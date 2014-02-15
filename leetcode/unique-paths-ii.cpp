#include "leetcode.h"
#include "array2D.hpp"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
      int n = obstacleGrid.size();
      if (n == 0) return 0;
      int m = obstacleGrid[0].size();
      if (m == 0) return 0;
      if (obstacleGrid[0][0] == 1) return 0;

      int npaths[105][105] = {0};
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (i == 0 && j == 0) {
            npaths[i][j] = 1;
            continue;
          }

          if (obstacleGrid[i][j] == 1)
            npaths[i][j] = 0;
          else {
            if (i > 0)
              npaths[i][j] += npaths[i-1][j];
            if (j > 0)
              npaths[i][j] += npaths[i][j-1];
          }
        }
      }

      return npaths[n-1][m-1];
    }
};

int main() {
  Solution sol;
  const int n = 3, m = 2;
  // int g[3][3] = {
  //   {0,0,0},
  //   {0,1,0},
  //   {0,0,0}
  // };

  int g[3][2] = {
    {0,0,},
    {1,1,},
    {0,0,}
  };

  Array2D<int>::type grid = fromCArray((int*) g, n, m);
  print_2D<int>(grid);

  int npaths = sol.uniquePathsWithObstacles(grid);
  cout << npaths << endl;

  return 0;
}