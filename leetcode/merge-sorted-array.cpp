#include <iostream>
using namespace std;

class SolutionV2 {
public:
    void merge(int A[], int m, int B[], int n) {
        int k = m + n - 1;
        int i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] >= B[j]) {
                A[k--] = A[i--];
            } else {
                A[k--] = B[j--];
            }
        }
        while (j >= 0) {
            A[k--] = B[j--];
        }
    }
};

// idea is to calculate space needed then merge from back
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
      int N = m + n;
      int j = m - 1, k = n - 1;
      for (int i = N - 1; i >= 0; i--) {
        if (k < 0 || (j >= 0 && A[j] >= B[k])) {
          A[i] = A[j];
          j--;
        } else if (j < 0 || (k >= 0 && A[j] < B[k])) {
          A[i] = B[k];
          k--;
        }
      }
    }
};


int main(int argc, char const *argv[])
{
  int A[] = {1, 3, 5, 5, 6, 7, 10};
  int B[] = {2, 4, 5, 8, 9, 11, 12, 13, 14};
  int m = sizeof(A) / sizeof(int);
  int n = sizeof(B) / sizeof(int);
  Solution sol;
  sol.merge(A, m, B, n);
  for (int i = 0; i < m+n; ++i)
  {
    cout << A[i] << " ";
  }
  cout << endl;
  return 0;
}