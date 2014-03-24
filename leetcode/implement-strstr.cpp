#include "leetcode.h"

class Solution {
public:
  char *strStr(char *haystack, char *needle) {
    if (haystack == NULL || needle == NULL) return NULL;
    if (needle[0] == '\0') return haystack;

    vector<int> partial = compute_partial_match_clrs(needle);
    int m = partial.size();
    int next = 0;  // points to next char of prefix in the needle

    int i = 0;
    while (haystack[i] != 0) {
      // current char in the haystack does not match next char in prefix: fall back
      while (next > 0 && haystack[i] != needle[next])
        next = partial[next-1];

      if (haystack[i] == needle[next]) {
        ++next;
      }

      // already reaches the end of needle
      if (next == m) {
        return &haystack[i+1-m];
      }
      ++i;
    } // while
    return NULL;
  }

  vector<int> compute_partial_match_clrs(char *needle) {
    // int n = needle.size();
    vector<int> partial;
    if (needle == NULL || needle[0] == '\0') return partial;

    int next = 0;       // the next character to match for the prefix
    partial.push_back(0);     // first char cannot be a proper suffix nor proper prefix
    int i = 1;
    while (needle[i] != 0) {
      // not a match: fall back until match or the 1st char (index = 0)
      while (next > 0 && needle[next] != needle[i])
        next = partial[next-1];

      // match to the current char of prefix
      if (needle[next] == needle[i])
        ++next;

      partial.push_back(next);
      ++i;
    }

    return partial;
  }
};

int main() {
  vector<char *> haystack {
    "",
    "abc",
    "",
    "bacbababaabcbab",
    "ABC ABCDAB ABCDABCDABDE",
    "ABABCABCABC"
  };
  vector<char *> needle {
    "",
    "",
    "abc",
    "abababca",
    "ABCDABD",
    "ABC", 
  };
  Solution sol;
  for (int i = 0; i < haystack.size(); ++i) {
    char *pos = sol.strStr(haystack[i], needle[i]);
    cout << (pos == NULL ? "NULL" : pos) << endl;
  }
  
  return 0;
}