#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
      int a = A[0];
      for (int i = 1; i < n; ++i)
      {
        a ^= A[i];
      }
      return a;
    }
};

int main() {
  Solution sol;
  int A[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
  cout << sol.singleNumber(A, 10) << endl;

  return 0;
}