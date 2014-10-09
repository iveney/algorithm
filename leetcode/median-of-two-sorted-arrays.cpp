// lots of edge cases, very annoying!
#include "leetcode.h"

class Solution {
public:
  double findMedian(int A[], int B[], int m, int n, int l, int r) {
    int N = m + n;
    if (l > r) {
      // assume m >= n so median is in A, otherwise flip the two arrays
      return findMedian(B, A, n, m, max(0, N/2 - m - 1), min(n - 1, (N+1)/2));
    }

    int i = (l + r) / 2;      // check if i is the median
    int j = (N-1) / 2 - i - 1;  // if yes, then j is the place around the median
    // cout << "l = " << l << " r = " << r << " m = " << m << " n = " << n;
    // cout << " i = " << i << " j = " << j << '\n';

    // when A strictly smaller than B, j < 0 <=> i == m-1, last elem in A
    // when A strictly larger than B, j == n - 1 <=> i == 0, first elem in A
    if ((j < 0 || n == 0 || (j < n && B[j] <= A[i])) &&
        (j >= n-1 || A[i] <= B[j+1])) {
      // we use the definition that median is the average between the two
      // when the total number is even
      if ( N % 2 != 0 ) {
        return A[i];
      } else {
        if ( j < 0 && n != 0 && i + 1 < m) {
          return (A[i] + min(B[0], A[i+1])) / 2.0;
        } else if (j >= n-1) {
          return (A[i] + A[i+1]) / 2.0;
        } else if (i + 1 < m) {
          return (A[i] + min(A[i+1], B[j+1])) / 2.0;
        } else {
          return (A[i] + B[j+1]) / 2.0; 
        }
      }
    } else if ((j < 0 || A[i] >= B[j]) && (j < n - 1) && A[i] >= B[j + 1]) {
      // A[i] larger than median
      return findMedian(A, B, m, n, l, i - 1);
    } else {
      return findMedian(A, B, m, n, i + 1, r);
    }
  }

  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int N = m + n;
    // assume B is strictly larger than m, then the median must be at max(0, N/2-n)
    // [ ...A... ] [ ...B ...]
    //    ^ somewhere here
    //    so the index will be N/2 - n in this case
    return findMedian(A, B, m, n, max(0, N/2 - n - 1), min(m - 1, (N+1)/2));
  }
};

int main() {
  vector<vector<int> > As{
    // {5,10},
    // {1, 3, 5, 6, 9, 11},
    // {2, 4, 7, 8},
    // {1, 3, 5, 7, 9, 11},
    // {1, 3, 5, 7},
    // {1, 2, 3, 4, 5},
    // {6, 7, 8, 9, 10},
    // {1},
    // {},
    // {2},
    // {2},
    // {1, 2, 3},
    // {1, 2, 3},
    // {},
    // {2,3},
    // {},
    // {1, 3},
    // {2},
    // {4},
    {1,2},
  };
  
  vector<vector<int> > Bs{
    // {1,9,11,16,24,28,32,46},
    // {2, 4, 7, 8},
    // {1, 3, 5, 6, 9, 11},
    // {2, 4, 6, 8},
    // {2, 4, 6, 8},
    // {6, 7, 8, 9, 10},
    // {1, 2, 3, 4, 5},
    // {2},
    // {2},
    // {},
    // {2},
    // {2, 3, 4, 5},
    // {2, 3, 4},
    // {2, 3},
    // {},
    // {1,2,3,4,5},
    // {2},
    // {1,3,4},
    // {1,2,3},
    {3,4,5,6,7},
  };

  int npairs = As.size();
  Solution sol;
  for (int i = 0; i < npairs; ++i) {
    cout << sol.findMedianSortedArrays(
      As[i].data(), As[i].size(), Bs[i].data(), Bs[i].size()) << '\n';
  }
  
  return 0;
}