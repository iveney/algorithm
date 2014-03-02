#include "leetcode.h"

// with memoization
class Solution {
  unordered_map<string, bool> memo;
public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    if (s == "") return true;

    int n = s.size();
    for (int i = 1; i <= n; ++i) {
      string prefix = s.substr(0, i);
      if (dict.find(prefix) == dict.end())
        continue;

      string remain = s.substr(i, n-i);

      if (memo.find(remain) != memo.end() &&
          memo[remain]) {
        // processed before
        return true;
      } else if (wordBreak(remain, dict)) {
        memo[remain] = true;
        return true;
      } else {
        memo[remain] = false;
      }
   }

   return false;
  }
};

int main() {
  Solution sol;
  vector<string> s = {
    // "leetcodecodeleet",
    // "feet",
    // "leevis",
    // "teef",
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
  };
  // unordered_set<string> dict = {"leet", "code", "feet", "cdma", "lee", "vis"};
  unordered_set<string> dict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
  for (auto str : s) {
    printf("%s : %d\n", str.c_str(), sol.wordBreak(str, dict));
  }
  
  return 0;
}