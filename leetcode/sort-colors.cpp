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

    // three pointers to the end of 0, 1, 2
    // when we encounter a number x, incement the pointers >= x
    // just like inserting one more element x into the range

    // e.g., the next element is 0:
    //idx : 0 1 2 3 4 5 6  7  8
    //      0 0 1 1 1 2 2 [0] 1
    //        i     j   k
    // increment i and insert 0, since there is one more element inserted
    // before the 1s, 1 also need to be incremented, similar, 2 need to be 
    // incremented, it becomes:
    //idx : 0 1 2 3 4 5 6 7  8
    //      0 0 0 1 1 1 2 2 [1]
    //          i     j   k
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