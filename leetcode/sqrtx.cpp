#include <limits>
#include "leetcode.h"

class Solution {
public:
  int sqrt(int x) {
    if (x < 0) return 0;
    if (x <= 1) return x;

    int l = 1, r = (1<<16)-1;
    do {
      unsigned int mid = l + (r - l) / 2;
      unsigned int sq = mid * mid;
      // printf("%d %d\n", mid, sq);
      if (sq == x)
        return mid;
      else if (sq > x) {
        r = mid;
      } else {
        l = mid;
      }
    } while (l < r - 1);
    return l;
  }
};

int main() {
  Solution sol;

  int n = 100;
  for (int i = 0; i <= n; ++i) {
    int xx = sol.sqrt(i);
    printf("%d^2 <= %d\n", xx, i);
  }

  return 0;
}