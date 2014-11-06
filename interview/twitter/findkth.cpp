// http://leetcode.com/2011/01/find-k-th-smallest-element-in-union-of.html
#include <vector>
#include <iostream>
#include <limits>
#include <cstdio>
#include <cassert>
using namespace std;

int findkth_linear(const vector<int> &A, const vector<int> &B, int k) {
  int i = 0, j = 0;
  int m = A.size();
  int n = B.size();
  if (k >= m + n) return -1;

  while (i < m && j < n && i + j < k) {
    if (A[i] < B[j]) {
      ++i;
    } else {
      ++j;
    }
  }

  if (i == m) {
      return B[k - i];
  } else if (j == n) {
      return A[k - j];
  } else {
    return min(A[i], B[j]);
  }
}

// find kth in log(m) + log(n) time
// idea:
// find i, j such that i + j == k
// if B[j-1] < A[i] < B[j], then A[i] is the kth largest
// or if A[i-1] < B[j] < A[i], then B[j] is the kth largest
// Otherwise, eliminate half of A and B:
// - if A[i] < B[j-1] < B[j],
//   - first half of A must be no use (larger i)
//   - second half of B must be no use (smaller j)
// - if B[j-1] < B[j] < A[i],
//   - second half of A no use (smaller i)
//   - first half of B no use (larger j)

int findkth_binary(const vector<int> &A, const vector<int> &B,
                   int Ab, int Ae, int Bb, int Be, int k) {
  int m = A.size();
  int n = B.size();
  if (k >= m + n) return -1;

  int i = (Ab + Ae) / 2;
  int j = k - i;

  // prevent i too small, and j far out of bound than n
  if (j > n) {
    j = n;
    i = k - j;
  } else if (j < 0) {
    // prevent i too large, and j far smaller than 0
    j = 0;
    i = k - j;
  }

  // if i == 0, view A[-1] = -INF, if i == m, view A[m] == INF to maintain the invariant i+j=k
  int Ai_1 = (i<=0) ? numeric_limits<int>::min() : A[i-1];
  int Bj_1 = (j<=0) ? numeric_limits<int>::min() : B[j-1];
  int Ai = (i>=m) ? numeric_limits<int>::max() : A[i];
  int Bj = (j>=n) ? numeric_limits<int>::max() : B[j];
  // printf("A[%d] = %d, A[%d] = %d, B[%d] = %d, B[%d] = %d\n", i-1, Ai_1, i, Ai, j-1, Bj_1, j, Bj);

  if (Bj_1 < Ai && Ai < Bj) {
    return Ai;
  }
  if (Ai_1 < Bj && Bj < Ai) {
    return Bj;
  }

  // note that if the above case is met, we have Ai < Bj_1 < Bj, but since Bj_1 is -INF, we compare with Bj
  if (Ai < Bj) {
    return findkth_binary(A, B, i + 1, Ae, Bb, j, k);
  } else {
    return findkth_binary(A, B, Ab, i, j + 1, Be, k);
  }
}

int main(int argc, char const *argv[]) {
  vector<int> A = {
    1,4,8,9,10,
  };
  vector<int> B = {
    0,2,3,5,6,7,11
  };

  // vector<int> A = {
  //   5,
  // };
  // vector<int> B = {
  //   0,1,2,3,4,6,7,8,9,
  // };

  // vector<int> A = {
  //   0,1,2,3,4,6,7,8,9,
  // };

  // vector<int> B = {
  //   5,
  // };

  for (int i = 0; i < A.size() + B.size() + 2; ++i) {
    cout << i << ": " << findkth_binary(A, B, 0, A.size(), 0, B.size(), i) << "\n";
    assert(findkth_binary(A, B, 0, A.size(), 0, B.size(), i) == 
           findkth_linear(A, B, i));
  }

  return 0;
}