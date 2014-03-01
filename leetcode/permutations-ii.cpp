#include "leetcode.h"
#include "array2D.hpp"

class Solution {
  vector<vector<int> > result;
  vector<bool> visited;
public:
  vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<int> prefix;
    sort(num.begin(), num.end());
    visited.assign(num.size(), 0);
    permuteUnique(prefix, num, 0);
    return result;
  }

  void permuteUnique(vector<int> prefix, vector<int> &num, int depth) {
    int n = num.size();
    if (depth == n) {
      result.push_back(prefix);
      return;
    }

    bool has_prev = false;
    int prev = -1;
    for (int i = 0; i < n; ++i) {
      if (visited[i] || (has_prev && num[i] == prev))
        continue;

      has_prev = true;
      prev = num[i];
      visited[i] = true;
      prefix.push_back(num[i]);
      permuteUnique(prefix, num, depth+1);
      prefix.pop_back();
      visited[i] = false;
    }
  }
};

int main() {
  Solution sol;
  vector<int> num {1, 1, 2, 2};
  auto result = sol.permuteUnique(num);
  print_2D<int>(result);
  
  return 0;
}