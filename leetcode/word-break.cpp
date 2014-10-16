#include "leetcode.h"

// idea: DP
// BS[i] : 0..i-1 can be broken in dict words,
// we only need to traverse the dict and set some j > i, where j-i+1 = word len
// can be broken if s[i..j] matches the word
class Solution {
public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    int n = s.size();
    vector<bool> bs(n + 1);
    bs[0] = true;
    for (int i = 0; i < n; ++i) {
      // cannot break from the previous, no need to start from this position
      if (!bs[i])
        continue;
      for (auto &word : dict) {
        int len = word.size();
        int end = i + len;
        if (end > n)
          continue;

        // can be broken somehow
        if (bs[end]) continue;

        if (s.substr(i, len) == word) 
          bs[end] = true;
      } // for
    } // for
    return bs[n];
  }
};

int main() {
  Solution sol;
  vector<string> s = {
    "leetcodecodeleet",
    "feet",
    "leevis",
    "teef",
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
    "",
  };
  // unordered_set<string> dict = {"leet", "code", "feet", "cdma", "lee", "vis"};
  unordered_set<string> dict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
  for (auto str : s) {
    printf("%s : %d\n", str.c_str(), sol.wordBreak(str, dict));
  }
  
  return 0;
}