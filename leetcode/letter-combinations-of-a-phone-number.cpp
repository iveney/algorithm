#include "leetcode.h"

class SolutionV2 {
public:
  vector<string> result;
  void dfs(string &prefix, string &digits, int i) {
    static const vector<string> letters = {
      "",
      "",
      "abc",
      "def",
      "ghi",
      "jkl",
      "mno",
      "pqrs",
      "tuv",
      "wxyz",
    };
    if (i == digits.size()) {
      result.push_back(prefix);
      return;
    }
    int d = digits[i] - '0';
    for (int j = 0; j < letters[d].size(); ++j) {
      prefix.push_back(letters[d][j]);
      dfs(prefix, digits, i + 1);
      prefix.pop_back();
    }
  }

  vector<string> letterCombinations(string digits) {
    string prefix;
    dfs(prefix, digits, 0);
    return result;
  }
};


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