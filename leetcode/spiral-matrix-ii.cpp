// very delicate case, potential improvement, can practice programming skills

#include "leetcode.h"
#include "array2D.hpp"

class Solution {
  enum DIR{R, D, L, U};
  DIR get_dir(DIR current_dir, int &dr, int &dc) {
    DIR next_dir = R;
    switch (current_dir) {
    case R:
      dr = 0;
      dc = 1;
      next_dir = D;
      break;
    case D:
      dr = 1;
      dc = 0;
      next_dir = L;
      break;
    case L:
      dr = 0;
      dc = -1;
      next_dir = U;
      break;
    case U:
      dr = -1;
      dc = 0;
      next_dir = R;
      break;
    default:
      break;
    } 
    return next_dir;
  }

public:
  vector<vector<int> > generateMatrix(int n) {
    int nn = n*n;
    vector<vector<int> > mat(n);
    if (n == 0) return mat;

    for (int i = 0; i < n; ++i) {
      mat[i].resize(n);
    }

    if (n == 1) {
      mat[0][0] = 1;
      return mat;
    }

    int val = 0;
    int half = (n+1) / 2;
    for (int cir = 0; cir < half; cir++) {
      int r = cir, c = cir;
      int dr = 0, dc = 0;
      for (int current_dir = 0; current_dir < 4; current_dir++) {
        get_dir((DIR)current_dir, dr, dc);
        for (int count = 0; count < n - 1 - 2*cir; count++, r+=dr, c+=dc) {
          mat[r][c] = ++val;
        }
      }
    } // for

    if (n % 2 != 0)
      mat[n/2][n/2] = ++val;
    return mat;
  }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  auto result = sol.generateMatrix(7);
  print_2D<int>(result);
  return 0;
}