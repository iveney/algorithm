#include "leetcode.h"

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
      int n = strs.size();
      if (n == 0) return "";
      if (n == 1) return strs[0];

      int i;
      string prefix;
      int l = 0;
      while (1) {
        if (l >= strs[0].size()) return prefix;
        char c = strs[0][l];
        for (int i = 1; i < n; ++i) {
          if (l >= strs[i].size()) return prefix;

          if (c != strs[i][l]) return prefix;
        }
        prefix.push_back(c);
        ++l;
      }
    }
};

int main() {
  vector<string> strs = {
    "abcbbb",
    "abc",
    "abcdef",
    "abccf",
    "abc"
  };
  Solution sol;
  cout << sol.longestCommonPrefix(strs) << endl;
  
  return 0;
}