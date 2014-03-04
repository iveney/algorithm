// very interesting problem.
#include "leetcode.h"

// idea: compute the highest from both direction
// then the max is find a pivoting poing in between
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
  for (auto &p : prices) {
    cout << sol.maxProfit(p) << endl;
  }
  
  return 0;
}