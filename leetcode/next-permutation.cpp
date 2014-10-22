// interesting question
// my idea:
// define next(i, n) as the next permutation in A[i .. n]:
// 1. A[i] + next(i+1, n) // reduce to next permutation in A[i+1 .. n]
// if 1 is not possible, then A[i+1 .. n] must be sorted in non-increasing order
// 2. swap A[i] and next number bigger than A[i] in A[i+1 .. n], say A[j]
//    reverse A[i+1 .. n]
#include "leetcode.h"

class SolutionV2 {
public:
  void nextPermutation(vector<int> &num) {
    int n = num.size();
    if (n <= 1) return;

    // search for the reversely sorted subarray, i is the first elem breaks this
    int i = n - 2;
    while (i >= 0 && num[i] >= num[i+1]) {
      --i;
    }

    // special case: whole sequence is reversely sorted, return to initial
    if (i < 0) {
      reverse(num.begin(), num.end());
      return; 
    }

    // find first elem in the reversely-sorted array that is larger than num[i] to swap
    int j = n - 1;
    while (num[j] <= num[i]) {
      --j;
    }

    swap(num[i], num[j]);

    // reverse the reversely sorted array
    reverse(num.begin() + i + 1, num.end());
  }
};

class Solution {
public:
  void nextPermutation(vector<int> &num) {
    if (num.size() <= 1)
      return;

    bool result = nextPermutation(num, 0);
    if (!result)
      reverse(num.begin(), num.end());
  }

  bool nextPermutation(vector<int> &num, int b) {
    int n = num.size();
    if (b == n - 2) {
      if (num[b] < num[n-1]) {
        swap(num[b], num[n-1]);
        return true;
      }
      return false;
    }
    int result = nextPermutation(num, b+1);
    if (result) {
      return true;
    } else {
      // num[b+1 .. n] already largest permutation
      // find next larger element than num[b]
      int nidx = b+1;
      int next = num[nidx];
      for (int i = b+1; i < n; ++i) {
        if (num[i] > num[b] && num[i] < next) {
          next = num[i];
          nidx = i;
        }
      }
      if (next <= num[b]) {
        // can't find such an element
        return false;
      }

      swap(num[b], num[nidx]);
      reverse(num.begin() + b + 1, num.end());
      return true;
    }
  }
};

int main() {
  // vector<int> num = {1,2,3,4}; 
  vector<int> num = {1,2,1,5,4,3,3,2,1}; 
  Solution sol;
  int np = 24;
  for (int i = 0; i < np; ++i) {
    sol.nextPermutation(num);
    copy(num.begin(), num.end(), 
      ostream_iterator<decltype(num)::value_type>(cout, " "));
    cout << '\n';
  }
  
  return 0;
}