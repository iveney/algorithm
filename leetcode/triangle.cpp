#include "leetcode.h"
#include "array2D.hpp"

class Solution {
public:
  int minimumTotal(vector<vector<int> > &triangle) {
    int n = triangle.size();
    if (n == 0) return 0;
    if (n == 1) return triangle[0][0];

    vector<int> p(n), q(n);
    q[0] = triangle[0][0];
    int min = 9999;
    for (int i = 1; i < n; ++i) {
      int m = triangle[i].size();
      p[0]   = q[0] + triangle[i][0];
      p[m-1] = q[m-2] + triangle[i][m-1];
      min = std::min(p[0], p[m-1]);
      for (int j = 1; j < m-1; ++j) {
        p[j] = std::min(q[j-1], q[j]) + triangle[i][j];
        if (p[j] < min)
          min = p[j];
      }
      q = p;
    } // for

    return min;
  }
};

int main() {
  // Array2D<int>::type triangle = {
  //    {2},
  //   {3,4},
  //  {6,5,7},
  // {4,1,8,3}
  // };
  Array2D<int>::type triangle = {
     {3},
    {3,3},
   {3,3,3},
  {1,3,3,2}
  };
  Solution sol;
  int result = sol.minimumTotal(triangle);
  cout << result << endl;

  return 0;
}