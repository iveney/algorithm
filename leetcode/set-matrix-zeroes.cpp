// tricky but genius solution. Practice and think again

#include "leetcode.h"
#include "array2D.hpp"

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
      int m = matrix.size();
      if (m == 0) return;
      int n = matrix[0].size();
      if (n == 0) return;

      bool row0has0 = false, col0has0 = false;
      for (int i = 0; i < m; ++i) {
        if (matrix[i][0] == 0) {
          col0has0 = true;
          break;
        }
      }

      for (int j = 0; j < n; ++j) {
        if (matrix[0][j] == 0) {
          row0has0 = true;
          break;
        }
      }

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (matrix[i][j] == 0) {
            matrix[i][0] = 0;
            matrix[0][j] = 0;
          }
        }
      }

      for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
          if (matrix[i][0] == 0 || matrix[0][j] == 0)
            matrix[i][j] = 0;
        }
      }

      if (row0has0) {
        for (int j = 0; j < n; ++j) {
          matrix[0][j] = 0;
        }
      }

      if (col0has0) {
        for (int i = 0; i < m; ++i) {
          matrix[i][0] = 0;
        }
      }
    }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  const int n = 5;
  int A[][n] = {
    {1, 2, 3, 4, 5},
    {6, 7, 0, 9, 10},
    {0, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {16, 17, 18, 19, 20},
    {16, 17, 18, 19, 20},
    {16, 17, 18, 19, 20},
  };

  int m = sizeof(A) / sizeof(int [n]);
  auto matrix = fromCArray<int> ((int*)A, m, n);
  print_2D<int>(matrix);
  cout << '\n';

  sol.setZeroes(matrix);
  print_2D<int>(matrix);
  return 0;
}