// interesting question. Failed to think about a solution
// Need to practice again
#include <cstdio>
#include "leetcode.h"

class Solution {
public:
    int trap(int A[], int n) {
      if (n == 0) return 0;

      vector<int> left(n, 0);
      int maxh = A[0];
      for (int i = 1; i < n; ++i) {
        left[i] = maxh;
        if (A[i] > maxh)
          maxh = A[i];
      }

      maxh = A[n-1];
      int sum = 0;
      for (int i = n - 2; i >= 1; --i) {
        int h = min(maxh, left[i]);
        if (h > A[i])
          sum += h - A[i];
        if (A[i] > maxh)
          maxh = A[i];
      }
      return sum;
    }
};

int main(int argc, char const *argv[])
{
  int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
  // int A[] = {0};
  // int A[] = {1, 0, 2};
  // int A[] = {};
  int n = sizeof(A) / sizeof(int);
  Solution sol;
  printf("%d\n", sol.trap(A, n));
  return 0;
}