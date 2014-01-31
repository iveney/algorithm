#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
      if (n <= 1) return n;
      int p = 1;
      int cur = A[0];
      for (int i = 1; i < n; i++) {
        if (A[i] == cur)
          continue;
        cur = A[i];
        A[p++] = cur;
      }
      return p;
    }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  // int A[] = {1,1,2,2,2,3,3,4,4,4,4,5,6,7,7,7};
  // int A[] = {3};
  int A[] = {3,3,3,3};
  int n = sizeof(A) / sizeof(int);
  int nn = sol.removeDuplicates(A, n);
  cout << "New length = " << nn << endl;
  for (int i = 0; i < nn; ++i)
  {
    cout << A[i] << " ";
  }
  cout << endl;
  return 0;
}