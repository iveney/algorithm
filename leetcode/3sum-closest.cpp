// good question, practice again
#include <limits>
#include "leetcode.h"

// O(nlog(n)) + O(n^2)
class Solution {
public:
  int p, q, r;
  vector<int> S;
  int threeSumClosest(vector<int> &num, int target) {
    // undefined
    int n = num.size();
    if (n < 3) return target;

    S.assign(num.begin(), num.end());
    sort(S.begin(), S.end());

    int min = S[n-1] + S[n-2] + S[n-3];
    for (int i = 0; i < n - 2; ++i) {
      int j = i+1;
      int k = n-1;
      while (j < k) {
        int sum = S[i] + S[j] + S[k];
        if (sum == target) return sum;

        if ( abs(sum - target) < abs(min - target) ) {
          p = i;
          q = j;
          r = k;
          min = sum;
        }
        if (sum > target) --k;
        else ++j;
      }
    } // for i

    return min;
  }
};

// wrong solution: maintaining three pointers does not give the sums in order
// O(nlog(n)) + O(n)
class WrongSolution {
public:
  int p, q, r;
  vector<int> S;
  int threeSumClosest(vector<int> &num, int target) {
    // undefined
    int n = num.size();
    if (n < 3) return target;

    S.assign(num.begin(), num.end());
    sort(S.begin(), S.end());
    p = 0; q = 1; r = 2;
    int closest = S[p] + S[q] + S[r];

    // minimum sum is already bigger than target
    if (closest >= target)
      return closest;

    while (p < n-2 || q < n-1 || r < n) {
      int cur = S[p] + S[q] + S[r];
      printf("p=%d, q=%d, r=%d, sum = %d\n", p, q, r, cur);
      // if (cur >= target)
      //   break;

      int sp, sq, sr;
      int *incr = NULL;
      int next = numeric_limits<int>::max();
      if (p+1 < q) {
        sp = S[p+1] + S[q] + S[r];
        if (sp < next) {
          next = sp;
          incr = &p;
        }
      }

      if (q+1 < r) {
        sq = S[p] + S[q+1] + S[r];
        if (sq < next) {
          next = sq;
          incr = &q;
        }
      }

      if (r+1 < n) {
        sr = S[p] + S[q] + S[r+1];
        if (sr < next) {
          next = sr;
          incr = &r;
        }
      }

      // all of them reach the end
      if (incr == NULL) break;
      ++(*incr);

      printf("next = %d\n", next);
      int delta = abs(cur - target);
      int new_delta = abs(next - target);
      if (new_delta < delta)
        closest = next;
      else
        closest = cur;

      if (next >= target) break;
    } // while

    return closest;
  }
};

int main() {
  vector< vector<int> > arrays = {
    {-1, 2, 1, -4},
    {-1, 2, 1, -4, 5},
    {1, 2, 5, -4},
    {12, 24, 55, -41, 23, -13, 4, 0, -9},
    {1, 1, 1, 0},
    {-1,0,1,2,-1,-4},
    {-3,-2,-5,3,-4},
  };
  int targets[] = {1, 2, 4, 0, 100, 0, -1};

  for (int i = 0; i < arrays.size(); ++i) {
    auto num = arrays[i];
    int target = targets[i];
    Solution sol;
    int sum = sol.threeSumClosest(num, target);
    int p = sol.p, q = sol.q, r = sol.r;
    printf("p=%d, q=%d, r=%d ", p, q, r);
    printf("%d + %d + %d = %d, | %d (sum) - %d (target)| = %d\n", 
      sol.S[p], sol.S[q], sol.S[r], sum,
      sum, target, abs(sum - target));
  }

  return 0;
}