// this can be done iteratively, like DP
// think and practice again
// http://oj.leetcode.com/discuss/15/how-to-adapt-subsets-i-solution-to-subsets-ii-problem

#include "leetcode.h"
#include "array2D.hpp"

class Solution {
  vector<vector<int> > result;
public:
  vector<vector<int> > subsets(vector<int> &S) {
    vector<int> prefix;
    sort(S.begin(), S.end());
    // result.push_back(prefix);

    subsets(S, prefix, -1);
    return result;
  }

  void subsets(vector<int> &S, vector<int> &prefix, int depth) {
    if (depth == S.size()) return;

    if (depth != -1) {
      prefix.push_back(S[depth]);
    }
    result.push_back(prefix);

    for (int i = depth+1; i < S.size(); ++i) {
      subsets(S, prefix, i);
    }

    if (!prefix.empty())
      prefix.pop_back();
  }
};

int main() {
  Solution sol;
  // int A[] = {};
  int A[] = {1, 2, 2};
  int n = sizeof(A) / sizeof(int);
  vector<int> S(A, A+n);
  auto result = sol.subsets(S);
  cout << "Total = " << result.size() << endl;
  print_2D<int>(result);

  return 0;
}