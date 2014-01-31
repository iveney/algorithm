#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int q = -1;
        int i=0;
        for (i = 0; i < n; ++i) {
          if (A[i] == elem) {
            // search for the next non-elem
            if ( q == -1 ) q = i + 1;
            while (q < n && A[q] == elem)
              ++q;

            // cannot find one
            if (q == n) break;

            // swap them
            A[i] = A[q];
            A[q] = elem;
          }
        }
        return i;
    }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  int A[] = {1, 2, 3, 3, 5, 3, 7, 8};
  // int A[] = {0};
  int elem = 3;
  int n = sizeof(A) / sizeof(int);
  int nn = sol.removeElement(A, n, elem);
  cout << nn << endl;
  for (int i : A)
    cout << i << " ";
  cout << endl;
  return 0;
}