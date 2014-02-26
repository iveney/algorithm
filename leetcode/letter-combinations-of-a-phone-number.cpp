#include "leetcode.h"

class Solution {
  vector<string> map = {
    " ",    // 0
    "",    // 1
    "abc", // 2
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz",
  };
public:
  vector<string> letterCombinations(string digits) {
    vector<string> result = {""};
    for(auto d: digits) {
      string &ch = map[d - '0'];
      vector<string> tmp = result;
      result.clear();
      int n = tmp.size();
      for (int i = 0; i < n; ++i) {
        for (char c: map[d - '0']) {
          result.push_back(tmp[i] + c);
        }
      }
    }// for

    return result;
  }
};

int main() {
  Solution sol;
  auto result = sol.letterCombinations("234");
  for(auto s: result) {
    cout << s << '\n';
  }
  
  return 0;
}