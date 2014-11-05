#include "leetcode.h"

// O(n) solution
// http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html

// Clever and easier than DP 
// O(n^2) solution (2n-1 possible strings)
class Solution {
  string expandFrom(string &s, int b, int e) {
    int n = s.size();
    if (e >= n) return "";
    while (b >= 0 && e < n && s[b] == s[e]) {
      --b;
      ++e;
    }
    return s.substr(b+1, e-b-1);
  }

public:
  string longestPalindrome(string s) {
    if (s.size() <= 1) return s;

    int n = s.size();
    string longest = s.substr(0, 1);
    for (int i = 0; i < n; ++i)
    {
      string p = expandFrom(s, i, i);
      string q = expandFrom(s, i, i+1);
      if (p.size() > longest.size())
        longest = p;
      if (q.size() > longest.size())
        longest = q;
    }
    return longest;
  }
};

// DP solution, O(n^2) space and time
class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.length();
    if (n <= 1) return s;

    bool ispal[1000][1000] = {false};
    // vector<vector<bool>> ispal(n, vector<bool>(n, false));
    int b=0, ml = 1;
    for (int l = 1; l <= n; ++l) {
      for (int i = 0; i <= n - l; ++i) {
        int j = i + l - 1;
        if (i == j) {
          ispal[i][j] = true;
        }
        if (s[i] == s[j] && (i+1 > j-1 || ispal[i+1][j-1])) {
          ispal[i][j] = true;
          if (l > ml) {
            b = i;
            ml = l;
          }
        }
      } // j
    } // i
    return s.substr(b, ml);
  }
};


int main() {
  Solution sol;
  vector<string> ss{
    "abacdfgdcaba",
    "caba",
    "abababa",
    "",
    "a",
    "ab",
    "aa",
    "abcdefg",
    "aaaaaaaaaaaaa",
  };
  for (auto s : ss) {
    cout << sol.longestPalindrome(s) << endl;
  }
  
  return 0;
}