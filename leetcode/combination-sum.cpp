#include "leetcode.h"
#include "array2D.hpp"

class Solution {
  vector<vector<int> > result;
public:
  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> prefix;
    combinationSum(candidates, 0, target, prefix);
    return result;
  }

  void combinationSum(const vector<int> &candidates, 
                      int begin, int target, vector<int>& prefix) {
    for (int i = begin; i < candidates.size(); ++i) {
      int v = candidates[i];
      if (v == target) {
        result.push_back(prefix);
        result.back().push_back(v);
      } else if (v < target) {
        prefix.push_back(v);
        combinationSum(candidates, i, target - v, prefix);
        prefix.pop_back();
      } else {
        break;
      }
    }
  }
};

int main() {
  Solution sol;
  int target = 7;
  // vector<int> candidates = {2,3,6,7};
  vector<int> candidates = {1, 2, 3, 4, 5, 6, 7};
  auto result = sol.combinationSum(candidates, target);
  print_2D<int>(result);
  
  return 0;
}