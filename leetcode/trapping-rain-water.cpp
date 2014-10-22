// interesting question. Failed to think about a solution
// Need to practice again

// The trick is to compute the water trapped for a single i independently, but not a "ridge" as a whole
// If we know the highest left and right boundary, we know the water trapped at i
// e.g., 

// 0 1 2 3 4 5 6
// 5 6 4 2 5 7 2

// for i=3, we can see that left highest is 6, right highest is 7,
// then the water at this point is min(6, 7) - A[3] = 6 - 2 = 4

// to do the above, we first find the l[i], which is the left highest between 0 .. i-1, 
// then we also find r[i], which is the right highest between i+1 .. n-1, note that both of them do not include i itself
// so the water trapped at i is min(l[i], r[i]) - A[i] (if > 0)
// Note that it is not necessary to keep r[i] since we only need information up to i, so we eliminate r[i] but use a single number to keep the right highest

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