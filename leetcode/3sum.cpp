#include "leetcode.h"
#include "array2D.hpp"

class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > result;
    sort(num.begin(), num.end());
    int n = num.size();
    for (int i = 0; i < n-2; ++i) {
      // we are done
      if (num[i] > 0) return result;

      // avoid duplicate
      if (i > 0 && num[i] == num[i-1])
        continue;

      int j = i+1, k = n-1;
      while (j < k) {
        int sum = num[i] + num[j] + num[k];
        if (sum > 0)
          --k;
        else if (sum < 0)
          ++j;
        else {
          vector<int> v{num[i], num[j], num[k]};
          if (result.empty() || result.back() != v)
            result.push_back(v);
          ++j;
          --k;
        }
      } // while
    } // for
    return result;
  }
};

int main() {
  Solution sol;
  vector<vector<int> > S {
    // {-1,0,1,2,-1,-4},
    {-1,0, -1, -1, 0, 0, 1, 1, 1},
  };

  for (auto &s : S) {
    auto result = sol.threeSum(s);
    print_2D<int> (result);
  }
  
  return 0;
}