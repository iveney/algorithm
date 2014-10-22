#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// the idea is to maintain a lowest point and compute the profit we can earn 
// at price[i], where i is greater than the current low point. Update the max accrodingly
class Solution {
public:
    int maxProfit(vector<int> &prices) {
      if (prices.empty()) return 0;
      int profit = 0;
      int low = prices[0];
      for (int i = 1; i < prices.size(); ++i) {
        low = min(prices[i], low);
        profit = max(profit, prices[i] - low);
      }
      return profit;
    }
};

int main(int argc, char const *argv[])
{
  // int A[] = {3, 4, 1, 2, 6, 7, 0, 2, 3};
  // int A[] = {3, 0};
  int A[] = {};
  int n = sizeof(A) / sizeof(int);
  vector<int> prices(A, A+n);
  Solution sol;
  int profit = sol.maxProfit(prices);
  cout << profit << endl;

  return 0;
}