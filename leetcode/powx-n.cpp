#include "leetcode.h"

class Solution {
public:
  double pow(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    bool inv = false;
    if (n < 0) {
      inv = true;
      n = -n;
    }

    if (n % 2 == 0) {
      double half = pow(x, n/2);
      double hh = half * half;
      return inv ? 1.0 / hh : hh;
    } {
      double half = pow(x, (n-1)/2);
      double hh = half * half * x;
      return inv ? 1.0 / hh : hh;
    }
  }
};

int main() {
  Solution sol;
  for (int i = -32; i <= 32; ++i) {
    printf("%.10e\n", sol.pow(34.00515, i));
    // cout << sol.pow(2, i) << '\n';
  }
  
  return 0;
}