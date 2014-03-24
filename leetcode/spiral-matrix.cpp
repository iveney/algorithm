#include "leetcode.h"
#include "array2D.hpp"

class Solution {
public:
  enum DIR{E, S, W,  N};
  int DI[4]  {0, 1, 0, -1};
  int DJ[4]  {1, 0, -1, 0};
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> result;
    int m = matrix.size();
    if (m == 0) return result;
    int n = matrix[0].size();
    if (n == 0) return result;

    // boundaries
    int T = -1, B = m, L = -1, R = n;
    // current dir
    DIR dir = E;

    int i = 0, j = 0;
    int remain = m*n;
    while (remain > 0) {
      int di = DI[dir], dj = DJ[dir];
      // printf("i=%d, j=%d\n", i, j);
      while (i > T && i < B && j > L && j < R) {
        result.push_back(matrix[i][j]);
        // cout << matrix[i][j] << endl;
        i += di;
        j += dj;
        remain--;
      }
      // update boundary and reset starting point
      switch(dir) {
      case E:
        ++i;
        --j;
        ++T;
        break;
      case S:
        --i;
        --j;
        --R;
        break;
      case W:
        --i;
        ++j;
        --B;
        break;
      case N:
        ++i;
        ++j;
        ++L;
        break;
      }
      dir = (DIR) ((dir+1) % 4);
    } // while

    return result;
  }
};

int main() {
  Solution sol;
  vector<vector<int> > matrix {
   { 1, 2, 3, 10 },
   { 4, 5, 6, 11},
   { 7, 8, 9, 12 },
   { 16, 15, 14, 13 },

   // { 1, 2, 3 },
   // { 4, 5, 6 },
   // { 7, 8, 9 }  

   // { 1, 2},
   // { 4, 5}

   // { 1}
  };

  print_2D<int> (matrix);
  auto result = sol.spiralOrder(matrix);
  copy(result.begin(), result.end(), 
    ostream_iterator<decltype(result)::value_type>(cout, " "));
  cout << '\n';
  
  return 0;
}