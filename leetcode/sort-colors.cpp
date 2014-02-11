#include <cstdio>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
      one_pass(A, n);
    }

    void two_pass(int A[], int n) {
      int count[3] = {0};
      for (int i = 0; i < n; ++i) {
        ++count[A[i]];
      }

      int k = 0;
      for (int i = 0; i < n; ++i) {
        while (count[k] <= 0) k++;
        A[i] = k;
        --count[k];
      }
    }

    void one_pass(int A[], int n) {
      int i, j, k;
      i = j = k = -1;
      for (int p = 0; p < n; ++p)
      {
        if (A[p] == 0) {
          A[++k] = 2;
          A[++j] = 1;
          A[++i] = 0;
        } else if (A[p] == 1) {
          A[++k] = 2;
          A[++j] = 1;
        } else if (A[p] == 2){
          A[++k] = 2;
        }
      }
    }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  // int A[] = {};
  // int A[] = {0};
  // int A[] = {1};
  // int A[] = {2};
  int A[] = {2, 1, 0, 1, 2, 1, 0, 2, 0};
  int n = sizeof(A) / sizeof(n);
  sol.sortColors(A, n);
  copy(A, A+n, ostream_iterator<int>(cout, " "));
  cout << '\n';
  return 0;
}