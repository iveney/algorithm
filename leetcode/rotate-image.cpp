#include "leetcode.h"
#include "array2D.hpp"

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
      int n = matrix.size();
      for (int i = 0; i < (n)/2; ++i) {
        int m = n - 1 - i;
        for (int j = i; j < m; ++j) {
          int &a = matrix[i][j];
          int &b = matrix[j][m];
          int &c = matrix[m][m-j+i];
          int &d = matrix[m-j+i][i];
          int tmp = d;
          d = c;
          c = b;
          b = a;
          a = tmp;
        }
      }
    }
};

int main() {
  const int n = 5;
  int A[][n] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
  };

  int m = sizeof(A) / sizeof(int [n]);
  auto matrix = fromCArray<int> ((int*)A, m, n);
  print_2D<int>(matrix);
  cout << '\n';

  Solution sol;
  sol.rotate(matrix);
  print_2D<int>(matrix);
	return 0;
}