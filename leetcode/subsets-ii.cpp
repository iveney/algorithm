#include <set>
#include "leetcode.h"
#include "array2D.hpp"

class Solution {
  set<vector<int> > result;
public:
  vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<int> prefix;
    sort(S.begin(), S.end());

    subsets(S, prefix, -1);
    vector<vector<int> > ret(result.begin(), result.end());
    return ret;
  }

  void subsets(vector<int> &S, vector<int> &prefix, int depth) {
    if (depth == S.size()) return;

    if (depth != -1) {
      prefix.push_back(S[depth]);
    }
    result.insert(prefix);

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
  auto result = sol.subsetsWithDup(S);
  cout << "Total = " << result.size() << endl;
  print_2D<int>(result);

  return 0;
}