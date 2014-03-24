#include "leetcode.h"
#include "array2D.hpp"

class Solution {
  vector<vector<int> > rb;

  void computeRbound(const vector<vector<char> > &matrix, int n, int m) {
    rb.resize(n);
    // compute left and right bound
    for (int i = 0; i < n; ++i) {
      rb[i].assign(m, -1);
      rb[i][m-1] = (matrix[i][m-1] == '0' ? -1 : m-1);
      for (int j = m-2; j >= 0; --j) {
        if (matrix[i][j] == '0')
          continue;
        int r = rb[i][j+1];
        rb[i][j] = (r != -1? r : j);
      }
    } // for
  }

  inline int computeArea(int llr, int llc, int urr, int urc) {
    return (urr - llr + 1) * (urc - llc + 1);
  }

public:
  int maximalRectangle(vector<vector<char> > &matrix) {
    int n = matrix.size();
    if (n == 0) return 0;
    int m = matrix[0].size();
    if (m == 0) return 0;

    computeRbound(matrix, n, m);

    int LLR, LLC, URR, URC;
    int maxarea = 0;
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < m; ++c) {
        if (matrix[r][c] == '0')
          continue;

        int urr = r, urc = rb[r][c];
        for (int urr = r; urr < n; ++urr) {
          if (matrix[urr][c] == '0')
            break;

          urc = min(rb[urr][c], urc);
          int area = computeArea(r, c, urr, urc);
          if (area > maxarea) {
            maxarea = area;
            LLR = r;
            LLC = c;
            URR = urr;
            URC = urc;
          }
        } // for urr
      } // for c
    } // for r
    // printf("(%d, %d) - (%d, %d) = %d\n", LLR, LLC, URR, URC, maxarea);
    return maxarea;
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