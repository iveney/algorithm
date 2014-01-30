#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
      int profit = 0;
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
        profit += prices[e] - prices[b];
        b = e + 1;
      }
      return profit;
    }
};

int main(int argc, char const *argv[])
{
	Solution sol;
  int v[] = {3, 2, 1, 4, 4, 5, 7, 3, 4, 2, 3};
  int v2[] = {3, 2, 1, 0};
  int N = sizeof(v) / sizeof(int);
  vector<int> prices(v, v + N);
  cout << sol.maxProfit(prices) << endl;

  prices.clear();
  cout << sol.maxProfit(prices) << endl;

  vector<int> p2(v2, v2+4);
  cout << sol.maxProfit(p2) << endl;

  int v3[] = {1, 2, 3, 0};
  vector<int> p3(v3, v3+4);
  cout << sol.maxProfit(p3) << endl;

  int v4[] = {1};
  vector<int> p4(v4, v4+1);
  cout << sol.maxProfit(p4) << endl;

  int v5[] = {2,1};
  vector<int> p5(v5, v5+1);
  cout << sol.maxProfit(p5) << endl;
	return 0;
}