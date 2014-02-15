// good question! think and practice again
// it's like a generalization of b-search
#include "leetcode.h"

class Solution {
public:
    bool search(int A[], int n, int target) {
      int b = 0, e = n-1;
      while (b <= e) {
        int m = (b+e) / 2;
        if (A[m] == target) {
          return true;
        } 

        // left half strictly sorted
        if (A[b] < A[m]) {
          if ( A[b] <= target && target <= A[m] ) {
            e = m-1;
          } else {
            b = m+1;
          }
        } else if (A[b] > A[m]) {
          // right half strictly sorted
          if (A[m] <= target && target <= A[e]) {
            b = m+1;
          } else {
            e = m-1;
          }
        } else {
          // otherwise we cannot remove by half
          b++;
        }
      } // while
      return false;
    }
};

int main(int argc, char const *argv[])
{
  int A[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1,};
  // int A[] = {4, 5, 6, 7, 0, 1, 2, 3};
  // int A[] = {0, 1, 2, 3, 4, 5, 6, 7, };
  // int A[] = {0};
  // int A[] = {};
  int n = sizeof(A) / sizeof(int);
  Solution sol;
  for (int i = -3; i < n + 3; ++i) {
    cout << i << " : " << sol.search(A, n, i) << endl;
  }

  return 0;
}