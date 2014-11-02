// good question to practice coding binary search

#include "leetcode.h"
#include "array2D.hpp"

// treat as a sorted list and do linear search
class SolutionLinear {
public:
  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    if (n == 0) return false;

    int b = 0, e = m * n - 1;
    while (b <= e) {
      int mid = (b + e) / 2;
      int mi = mid / n;
      int mj = mid % n;
      if (matrix[mi][mj] == target) {
        return true;
      } else if (matrix[mi][mj] < target) {
        b = mid + 1;
      } else {
        e = mid - 1;
      }
    }
    return false;
  }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
      int m = matrix.size();
      if (m == 0) return false;
      int n = matrix[0].size();
      if (n == 0) return false;

      int b = 0, e = m-1;
      bool found = false;
      while (b <= e) {
        int mid = (b+e)/2;
        int v = matrix[mid][0];
        if (v == target) {
          return true;
        } else if (v > target) {
          e = mid - 1;
        } else {
          b = mid + 1;
        }
      }

      int row = b - 1;
      // smaller than all
      if (row < 0) return false;
      b = 0, e = n-1;
      while (b <= e) {
        int mid = (b+e)/2;
        int v = matrix[row][mid];
        if (v == target) {
          return true;
        } else if (v > target) {
          e = mid - 1;
        } else {
          b = mid + 1;
        }
      }

      return false;
    }
};

int main(int argc, char const *argv[])
{
  const int m = 3, n = 4;
  int A[m][n] = {
    {1,   3,  5,  7},
    {10, 11, 16, 20},
    {23, 30, 34, 50}
  };

  auto matrix = fromCArray<int>((int*)A, m, n);
  print_2D<int>(matrix);

  int target = 50;
  Solution sol;
  cout << sol.searchMatrix(matrix, target) << endl;

  return 0;
}