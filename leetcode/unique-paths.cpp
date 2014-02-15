#include "leetcode.h"

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