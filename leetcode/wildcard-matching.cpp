#include "leetcode.h"

class Solution {
public:
  bool isMatch(const char *s, const char *p) {
    if (s == NULL || p == NULL) return true;

    int i = 0, j = 0;
    int laststar = -1, lastmatch = -1;
    while (s[i] != 0) {
      if (p[j] == '*') {
        // current target is *, track it for later fallback
        laststar = j;
        lastmatch = i;
        ++j;
      } else if (p[j] == '?' || s[i] == p[j]) {
        // match current char
        ++i;
        ++j;
      }
      else if (laststar != -1) {
        // not '*' and doesn't match, try to fall back to laststar '*'
        // to make a match. Also advance pattern pointer
        i = lastmatch;
        ++lastmatch;
        j = laststar + 1;
      } else {
        // no match and can't fallback: fail
        return false;
      }
    } // while

    // traverse the remaining of p to see if there is any non-wildcard
    while (p[j] != 0 && p[j] == '*') {
      ++j;
    }
    return p[j] == 0;
  }
};

class SolutionRecursive {
public:
  bool isMatch(const char *s, const char *p) {
    if (s == NULL || p == NULL) return true;
    // cout << "Comparing: " << s << " vs " << p << endl;

    int i = 0, j = 0;
    while (s[i] != 0 && p[j] != 0) {
      if (p[j] == '*') {
        // '*' case
        // compress consecutive '*'
        while (p[j + 1] == '*') {
          ++j;
        }
        return isMatch(s + i, p + j + 1) ||  // match zero char
               isMatch(s + i + 1, p + j);    // match one or more
      } else if (p[j] == '?' || s[i] == p[j]) {
        ++i;
        ++j;
      } else {
        return false;
      }
    } // while

    if (s[i] == 0) {
      if (p[j] == 0) return true;
      else {
        // traverse the remaining of p to see if there is any non-wildcard
        while (p[j] != 0 && p[j] == '*') {
          ++j;
        }
        return p[j] == 0;
      }
    } else {
      return false;
    }
  }
};

int main() {
  Solution sol;
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
    "asdfadsf",
    "asdfadsf",
    "cccaddd",
    "aab",
    "aab",
    "aaab",
    "aaaab",
    "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba",
    "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb",
    "hi",
    "ab*cdec",
  };
  vector<string> pattern {
    "",
    "a",
    "aa",
    "aa",
    "a*",
    "?*",
    "?*",
    "c*a*b",
    "?*ab",
    "a?*cb",
    "b*?*a?",
    "a*aaab",
    "a*aab",
    "a*aab",
    "a*ab",
    "a*b",
    "ab*",
    "ab*",
    "ab*",
    "a",
    "?",
    "",
    "*",
    "***",
    "*a*",
    "aaab",
    "*aaab",
    "a*aaab",
    "a*aaab",
    "a*******b",
    "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb",
    "*?",
    "ab*c",
  };

  for (int i = 0; i < target.size(); ++i) {
    const char *s = target[i].c_str();
    const char *p = pattern[i].c_str();
    bool result = sol.isMatch(s, p);
    printf("'%s' : '%s' -> %d\n", s, p, (int)result);
  }
  
  return 0;
}