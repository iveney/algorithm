// good question, think about DP
#include "leetcode.h"

class Solution {
public:

  // clumsy solution but O(n) space time and memory
  // idea is to identify all 0, break the array to sub-arrays that do not contain 0
  // for each subarray, if it contains even number of negative, then the max is multiply all
  // otherwise, compare the product of [begin..last neg -1] and [first neg + 1 .. end]
  // such that the num negs are even
  int maxProduct(int A[], int n) {
    if (n == 1) {
      return A[0];
    }

    int result = A[0];
    // find all the zeros and negatives
    vector<int> negs, zeros;
    int b = 0, e = 0;
    int prod = 1;
    for (int i = 0; i <= n; ++i)
    {
      if (b >= n) {
        break;
      }
      if (A[b] == 0) {
        // the starting point should not be zero
        ++b;
        continue;
      }

      // in case 0 is largest
      if (i < n && A[i] > result) {
        result = A[i];
      }

      if (i == n || A[i] == 0) {
        // encounter a delimiter (0 or end)
        if (negs.size() % 2 == 0) {
          // this range contains even number of negs
          result = max(result, prod);
        } else {
          // odd number of negs, compare two range
          int p1 = (b < negs.back()) ? 1:0;
          for (int k = b; k < negs.back(); ++k) {
            p1 *= A[k];
          }
          int p2 = (negs.front() + 1 < i) ? 1:0;
          for (int k = negs.front() + 1; k < i; ++k) {
            p2 *= A[k];
          }
          result = max({result, p1, p2});
        }

        // reset for next segment
        b = i + 1;
        negs.clear();
        prod = 1;
      } else {
        prod *= A[i];
        if (A[i] < 0) {
          negs.push_back(i);
        }
      }
    }

    return result;
  }
};

int main() {
  // int A[] = {-6, -3, 0, -1};
  // int A[] = {2,3,-2,4};
  // int A[] = {0, 0, 0};
  // int A[] = {0, 0, 0, 1};
  int A[] = {1,2,3,0,2,3,4,0,-3,4,-5,0,-5,-5,-5};
  // int A[] = {-5,0,-3,0,-4};
  // int A[] = {-2};
  Solution sol;
  cout << sol.maxProduct(A, sizeof(A) / sizeof(int)) << endl;
  
  return 0;
}