// this is a good problem, practice one more time

#include <algorithm>
#include <iterator>
#include "leetcode.h"

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
      vector<int> prefix;
      return helper(prefix, 1, n, k);
    }

    vector<vector<int> > helper(const vector<int> &prefix, int b, int n, int k) {
      vector<vector<int> > result;
      if (k <= 0) {
        result.push_back(prefix);
        return result;
      }

      int remain = n - b + 1;
      if ( remain <= k ) {
        vector<int> tmp(prefix);
        for (int i = b; i <= n; i++)
          tmp.push_back(i);
        result.push_back(tmp);
        return result;
      }

      for (int i = b; i <= n - k + 1; ++i) {
        vector<int> new_prefix(prefix);
        new_prefix.push_back(i);
        auto ret = helper(new_prefix, i+1, n, k-1);
        copy(ret.begin(), ret.end(), back_inserter(result));
      }

      return result;
    }
};

int main(int argc, char const *argv[])
{
	Solution sol;
  auto result = sol.combine(5, 4);
  for (auto row : result) {
    for (auto val : row) {
      cout << val << " ";
    }
    cout << '\n';
  }
	return 0;
}