#include "leetcode.h"
#include "array2D.hpp"

class Solution {
public:
  bool isPalindrome(string &s) {
    int i = 0, j = s.size() - 1;
    while (i <= j) {
      if (s[i] != s[j])
        return false;
      ++i;
      --j;
    }
    return true;
  }

  vector<vector<string> > partition(string s) {
    vector<vector<string> > result;
    int n = s.size();
    for (int i = 1; i <= n; ++i) {
      string sub = s.substr(n-i, i);
      if ( isPalindrome(sub) ) {
        string remain = s.substr(0, n-i);
        vector<vector<string> > tmp = partition(remain);
        if (tmp.empty())
          result.push_back(vector<string>(1, sub));
        for (auto vec: tmp) {
          result.push_back(vec);
          result.back().push_back(sub);
        }
      }
    } // for

    return result;
  }
};

int main() {
  Solution sol;
  vector<string> strs = {
    "ab",
    "aab",
    "abba",
    "abcba",
    "a",
    "",
  };
  for (auto s : strs) {
    cout << s << ": [\n";
    auto result = sol.partition(s);
    print_2D<string>(result);
    cout << "]\n";
  }
  
  return 0;
}