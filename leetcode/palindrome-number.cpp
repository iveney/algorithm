#include "leetcode.h"

class Solution {
public:

  // overflow version
  bool isPalindrome(int x) {
    int orig = x;
    x = abs(x);
    long long y = 0;
    while (x != 0) {
      int d = x % 10;
      x /= 10;
      y = 10 * y + d;
    } 
    return orig == y;
  }
};

int main(int argc, char const *argv[])
{
  int x = 123454321;
  Solution sol;
  cout << sol.isPalindrome(x) << endl;

  int neg = -x;
  cout << sol.isPalindrome(x) << endl;

  int big = 0x7fffffff;
  cout << big << endl;
  cout << sol.isPalindrome(big) << endl;
  return 0;
}