#include <iostream>
using namespace std;

class Solution {
public:
  const static int MAX = 10000;
  int numTrees(int n) {
    int a[MAX];
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;

    for (int j = 3; j <= n; ++j) {
      int sum = 0;
      for (int i = 0; i <= (j-2) / 2; ++i)
      {
        sum += a[i] * a[j-1-i];
      }
      a[j] = 2 * sum;
      if (j % 2 != 0) {
        int t = a[(j-1)/2];
        a[j] += t * t;
      }
    }

    return a[n];
  }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  cout << sol.numTrees(3) << endl;
  cout << sol.numTrees(4) << endl;
  cout << sol.numTrees(5) << endl;
  return 0;
}