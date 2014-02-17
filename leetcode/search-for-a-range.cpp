#include "leetcode.h"

class Solution {
public:
  vector<int> searchRange(int A[], int n, int target) {
    int l = bsearch(A, 0, n-1, target);
    if ( l >= n || A[l] != target ) {
      return vector<int>{-1, -1};
    }

    int r = bsearch(A, 0, n-1, target+1);
    return vector<int>{l, r-1};
  }

  // return index of the leftmost target, or the insert position
  int bsearch(int A[], int b, int e, int target) {
    if (b > e) return e+1;

    int m = (b+e) / 2;
    if (A[m] == target) {
      int l = bsearch(A, b, m-1, target);
      if (l != -1)
        return l;
      else
        return m;
    } else if (A[m] < target) {
      return bsearch(A, m+1, e, target);
    } else {
      return bsearch(A, b, m-1, target);
    }
  }
};

int main() {
  Solution sol;
  int A[] = {5, 7, 8, 8, 8, 8, 9, 10};
  int target = 8;
  int n = sizeof(A) / sizeof(int);
  auto result = sol.searchRange(A, n, target);
  printf("%d, %d\n", result[0], result[1]);
  
  return 0;
}