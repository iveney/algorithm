#include "leetcode.h"
#include "array2D.hpp"

class Solution {
public:
  int maximalRectangle(vector<vector<char> > &matrix) {
    int n = matrix.size();
    if (n == 0) return 0;
    int m = matrix[0].size();
    if (m == 0) return 0;

    // compute left and right bound
    vector<vector<int> > lb(n), rb(n);
    for (int i = 0; i < n; ++i) {
      lb[i].assign(m, -1);
      rb[i].assign(m, -1);
      lb[i][0]   = (matrix[i][0]   == '0' ? -1 : 0);
      rb[i][m-1] = (matrix[i][m-1] == '0' ? -1 : m-1);
      for (int j = 1; j < m; ++j) {
        if (matrix[i][j] == '0')
          continue;
        int l = lb[i][j-1];
        lb[i][j] = (l != -1? l : j);
      }
      for (int j = m-2; j >= 0; --j) {
        if (matrix[i][j] == '0')
          continue;
        int r = rb[i][j+1];
        rb[i][j] = (r != -1? r : j);
      }
    } // for

    int area = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (lb[i][j] == -1) continue;

        int L = lb[i][j], R = rb[i][j];

        // the maximal of this line has been computed before
        if (i - 1 >= 0 && L == lb[i-1][j] && R == rb[i-1][j])
          continue;
        int width = R - L + 1;
        int height = 1;

        // go up
        for (int k = i-1; k >= 0; --k) {
          if (lb[k][j] <= L && rb[k][j] >= R) {
            ++height;
          } else {
            break;
          }
        }
        // go down
        for (int k = i+1; k < n; ++k) {
          if (lb[k][j] <= L && rb[k][j] >= R) {
            ++height;
          } else {
            break;
          }
        }
        printf("%d,%d, w=%d, h=%d\n", i, j, width, height);
        area = max(area, width * height);
        j = R;  // skip this line
      } // for j
    } // for i
    return area;
  }
};

int main() {
  char buf[] = 
"111111011111111"
"101101111111111"
"111111111111111"
"011111101110111"
"100111111110111"
"111111111111111"
"111011111110111"
"111100011111010"
"101100011110101"
"101111110111011"
"101111111111111"
"111011111111111"
"111000101111111"
"111111011111111"
"111111101111101"
  ;
  auto matrix = fromCArray(buf, 15, 15);
  print_2D<char> (matrix);
  Solution sol;
  int area = sol.maximalRectangle(matrix);
  printf("%d\n", area);
  
  return 0;
}