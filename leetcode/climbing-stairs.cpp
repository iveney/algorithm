#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
      int *table = new int[n+1];
      table[0] = 0;
      table[1] = 1;
      table[2] = 2;
      for (int i = 3; i <= n; ++i) {
        table[i] = table[i-1] + table[i-2];
      }
      return table[n];
    }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  int n = 5;
  int nsol = sol.climbStairs(n);
  cout << nsol << endl;
  return 0;
}