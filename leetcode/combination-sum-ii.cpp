#include "leetcode.h"
#include "array2D.hpp"

class Solution {
  vector<vector<int> > result;
public:
  vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    // copy(num.begin(), num.end(), 
    // ostream_iterator<int>(cout, " "));
    // cout << ", target = " << target << '\n';
    vector<int> prefix;
    combinationSum2(num, target, prefix, 0);
    return result;
  }

  void combinationSum2(vector<int> &num, int target, vector<int> &prefix, int depth) {
    int n = num.size();
    if (depth >= n) return;

    for (int i = depth; i < n; ++i) {
      if (i-1 >= depth && num[i] == num[i-1])
        continue;
      prefix.push_back(num[i]);
      if (num[i] == target) {
        result.push_back(prefix);
      } else if (num[i] < target) {
        combinationSum2(num, target - num[i], prefix, i+1);
      }
      prefix.pop_back();
    }
  }
};

int main() {
  vector<vector<int> > num {
    {10,1,2,7,6,1,5},
    {},
    {1},
    {1, 1, 1},
    {1, 1, 2},
  };

  vector<int> target {
    8,
    0,
    0,
    2,
    2,
  };

  for (int i = 0; i < num.size(); ++i) {
    Solution sol;
    auto result = sol.combinationSum2(num[i], target[i]);
    print_2D<int>(result);
  }

  return 0;
}