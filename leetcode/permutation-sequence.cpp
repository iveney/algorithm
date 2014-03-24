#include <algorithm>
#include <list>
#include "leetcode.h"

// idea: each time determine the number at ith position
// by counting how many permutaitons left
class Solution {
public:
  string getPermutation(int n, int k) {
    string result;
    vector<char> l(n, '1');
    int fac = 1;
    for (int i = 0; i < n; ++i) {
      fac *= (i+1);
      l[i] += i;
    }

    k -= 1;
    k %= fac;
    for (int i = 0; i < n; ++i) {
      fac /= (n-i);
      int idx = k / fac;
      k %= fac;
      result.push_back(l[idx]);
      l.erase(l.begin() + idx);
    }

    return result;
  }
};

int main() {
  Solution sol;

  for (int i = 1; i <= 25; ++i) {
    cout << sol.getPermutation(4, i) << endl;
  }

  cout << sol.getPermutation(8, 30654) << endl;
  
  return 0;
}