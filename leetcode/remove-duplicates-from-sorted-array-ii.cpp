#include "leetcode.h"

class Solution {
public:
    int removeDuplicates(int A[], int n) {
      if (n <= 2) return n;

      int nn = 0;
      int count = 1;
      for (int i = 1; i < n; i++) {
        if (A[i] == A[nn]) {
          if (count < 2) {
            A[++nn] = A[i];
            count++;
          }
        } else {
          A[++nn] = A[i];
          count = 1;
        }
      } // for

      return nn + 1;
    }
};

int main(int argc, char const *argv[])
{
  // int A[] = {1, 1, 1, 2, 2, 3};
  // int A[] = {1, 2};
  // int A[] = {2};
  // int A[] = {};
  int A[] = {1, 1, 1, 1, 1, 2, 3, 3, 3, 3,};
  int n = sizeof(A) / sizeof(int);
  Solution sol;
  int nn = sol.removeDuplicates(A, n);

  for (int i = 0; i < nn; ++i)
  {
    cout << A[i] << " ";
  }
  cout << '\n';

  return 0;
}