#include "leetcode.h"

class Solution {
public:
  int firstMissingPositive(int A[], int n) {
    // recursively swap all the elements in range 1-n
    for (int i = 0; i < n; ++i) {
      // move to right place
      int pos = A[i];
      while ( pos > 0 && pos <= n && A[pos-1] != pos ) {
        int tmp = A[pos-1];
        A[pos-1] = pos;
        pos = tmp;
      }

      // knock out some out of range element
      if ( pos <= 0 || pos > n ) {
        A[i] = pos;
      }
    } // for

    // scan for the missing positive
    for (int i = 0; i < n; ++i) {
      if (A[i] != i+1) return i+1;
    }

    // no such element exist
    return n+1;
  }
};

int main() {
  Solution sol;

  vector<vector<int> > As {
    {1, 2, 0},
    {3, 4, -1, 1},
    {4, 3, 2, 0, 6, 5},
    {4, 3, 2, 1, 6, 5},
    {4, 3, 1, 0, 6, 5},
    {},
    {1},
  };

  for (auto &A : As) {
    int missing = sol.firstMissingPositive(A.data(), A.size());
    printf("%d\n", missing);
  }

  return 0;
}