// very interesting problem.
#include "leetcode.h"

// An intuitive (but wrong) thought:
// Compute all possible buy-low-sell-high segments, and choose the highest two.
// The problem is, a buy-low-sell-high segment may cross multiple these segments and has higher profit.
// We can take this segment and take another one to maximize profit.
// e.g., {1, 6, 5, 10, 7, 8, 5, 7},
// - Using the wrong idea, we can (1, 6), (5, 10), (7, 8), (5, 7), max will be (1, 6) and (5, 10) = 10
// - Correct solution: note that (1, 6, 5, 10) gives max profit 9 (taking 1 and 10), and we can add (5, 7)=2 to maximize profit as 11

// idea: use DP to compute an array L, where L[i] denotes the max among 0..i
// also compute and array R, where R[i] denotes the max among i..n-1
// then the max two can be found by finding a pivot that maximize L[i-1] + R[i];

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    if (n <= 1) return 0;

    vector<int> lr(n);
    int low = 0;
    for (int i = 1; i < n; ++i) {
      lr[i] = max(prices[i] - prices[low], lr[i-1]);
      if (prices[i] < prices[low])
        low = i;
    }

    vector<int> rl(n);
    int high = n-1;
    for (int i = n-2; i >= 0; --i) {
      rl[i] = max(prices[high] - prices[i], rl[i+1]);
      if (prices[i] > prices[high])
        high = i;
    }

    int M = 0;
    for (int i = 1; i < n; ++i) {
      // printf("%d : %d + %d\n", i, lr[i-1], rl[i]);
      M = max(M, lr[i-1] + rl[i]);
    }
    M = max({M, lr[n-1], rl[0]});
    return M;
  }
};

class SolutionWrong {
public:
  int maxProfit(vector<int> &prices) {
    vector<int> maxtwo(2, 0);
    int n = prices.size();
    int b = 0, e = 0;
    while ( b < n ) {
        // decreasing
      while ( b+1 < n && prices[b+1] <= prices[b] )
        ++b;

      if (b == n) break;

      e = b;
        // increasing
      while ( e == 0 || (e+1 < n && prices[e+1] >= prices[e]) )
        ++e;

      if (e == n) break;

      int val = prices[e] - prices[b];
      if (val > maxtwo[0]) {
        maxtwo[1] = maxtwo[0];
        maxtwo[0] = val;
      } else if (val > maxtwo[1]) {
        maxtwo[1] = val;
      }
      b = e + 1;
    }
    return maxtwo[0] + maxtwo[1];
  }
};

int main() {
  vector<vector<int > > prices {
    {5, 4, 3, 2, 1, 2},
    {5, 4, 3, 2, 1},
    {4, 4, 4, 4, 4},
    {1, 2, 3, 4, 5},
    {1, 2, 3, 4, 5, 4},
    {1, 2, 3, 4, 5, 1, 2, 3, 4, 1, 2, 3, 4, 5},
    {},
    {1},
    {1, 6, 5, 10, 7, 8, 5, 7},
    {1,2,4,2,5,7,2,4,9,0},
    {5, 10, 5, 10},
    {8,3,6,2,8,8,8,4,2,0,7,2,9,4,9},
  };
  Solution sol;
  SolutionWrong sol2;
  for (auto &p : prices) {
    cout << "sol 1: " << sol.maxProfit(p) << endl;
    cout << "sol 2: " << sol2.maxProfit(p) << endl;
  }
  
  return 0;
}