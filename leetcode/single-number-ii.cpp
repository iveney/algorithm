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
      for (int i = 0; i < n; ++i)
      {
        threes = twos & A[i];
        twos |= ones & A[i]; // appeared 2 or 3 times
        ones ^= A[i];        // appeared exactly once
        ones &= ~threes;
        twos &= ~threes;
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