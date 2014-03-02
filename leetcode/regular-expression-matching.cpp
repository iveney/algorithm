// interesting, think again
#include "leetcode.h"

class Solution {
public:
  bool isMatch(const char *s, const char *p) {
    if (s[0]!=0 && p[0] == 0) return false;
    return isMatch(s, 0, p, 0);
  }

  // assume no '**' exist
  bool isMatch(const char *s, int sp, const char *p, int pp) {
    if (s[sp] == 0 && p[pp] == 0) return true;
    // if (s[sp] == 0 || p[pp] == 0) return false;

    char c = p[pp], peek = p[pp+1];
    if (peek == '*') {
      // its wildcard matching: recursively match all prefix
      while (s[sp] != 0 && (s[sp] == c || c == '.')) {
        if ( isMatch(s, sp, p, pp+2) ) return true;
        ++sp;
      }

      // now s[sp] == 0 or s[sp] != c
      return isMatch(s, sp, p, pp+2);
    } else {
      // must match current character
      return (s[sp] == c || (c == '.' && s[sp] != 0) ) && 
             isMatch(s, sp+1, p, pp+1);
    }
  }
};

int main() {
  vector<string> target {
    "a",
    "aa",
    "aa",
    "aaa",
    "aa",
    "aa",
    "ab",
    "aab",
    "aaab",
    "aacb",
    "bbbcccaa",
    "aaab",
    "aaab",
    "aaab",
    "aaab",
    "aaab",
    "abbb",
    "ab",
    "a",
    "aaa",
    "",
    "b",
  };
  vector<string> pattern {
    "",
    "a",
    "aa",
    "aa",
    "a*",
    ".*",
    ".*",
    "c*a*b",
    ".*ab",
    "a.*cb",
    "b*.*a.",
    "a*aaab",
    "a*aab",
    "a*aab",
    "a*ab",
    "a*b",
    "ab*",
    "ab*",
    "ab*",
    "a",
    ".",
    "",
  };
  Solution sol;

  for (int i = 0; i < target.size(); ++i) {
    const char *s = target[i].c_str();
    const char *p = pattern[i].c_str();
    bool result = sol.isMatch(s, p);
    printf("%s : %s -> %d\n", s, p, (int)result);
  }

  cout << sol.isMatch("b", "") << '\n';
  
  return 0;
}