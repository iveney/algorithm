// http://oj.leetcode.com/discuss/857/constant-space-solution
#include <iostream>
using namespace std;

class Solution {
public:;
    int singleNumber(int A[], int n) {
      // ones: appeared exactly once
      // twos: appeared exactly twice
      // threes: appeared exactly three times
      int ones = 0, twos = 0, threes = 0;
      for (int i = 0; i < n; ++i) {
        int tmp = twos;
        threes = twos & A[i];
        twos |= ones & A[i];          // ones & A[i]: increment to two
        twos &= ~threes;              // remove threes
        ones = (ones ^ A[i]) & ~tmp;
      }
      return ones;
    }
};

int main(int argc, char const *argv[])
{
  // int A[] = {1, 2, 3, 1, 4, 2, 3, 1, 2, 3};
  // int A[] = {4};
  // int A[] = {4, 1, 1, 1};
  int n = sizeof(A) / sizeof(n);
  Solution sol;
  cout << sol.singleNumber(A, n) << endl;
  return 0;
}