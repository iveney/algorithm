// good question! think and practice again
// it's like a generalization of b-search
#include "leetcode.h"

class Solution {
public:
    int search(int A[], int n, int target) {
      int b = 0, e = n-1;
      while (b <= e) {
        int m = (b+e) / 2;
        if (A[m] == target) {
          return m;
        } 

        if (A[b] <= A[m]) {
          if ( A[b] <= target && target <= A[m] ) {
            e = m-1;
          } else {
            b = m+1;
          }
        } else { // A[b] > A[m]
          if (A[m] <= target && target <= A[e]) {
            b = m+1;
          } else {
            e = m-1;
          }
        }
      } // while
      return -1;
    }
};

int main(int argc, char const *argv[])
{
  int A[] = {4, 5, 6, 7, 0, 1, 2, 3};
  // int A[] = {0, 1, 2, 3, 4, 5, 6, 7, };
  // int A[] = {0};
  // int A[] = {};
  int n = sizeof(A) / sizeof(int);
  Solution sol;
  for (int i = -3; i < n + 3; ++i) {
    cout << sol.search(A, n, i) << endl;
  }

  return 0;
}