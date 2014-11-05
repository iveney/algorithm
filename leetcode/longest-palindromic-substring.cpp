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
class Solution_DP {
public:
  string longestPalindrome(string s) {
    if (s.size() <= 1) return s;

    int n = s.size();
    vector<vector<int> > len(n);
    for (int i = 0; i < n; ++i)
    {
      len[i].resize(n);
      len[i][i] = 1;
    }

    int maxlen = 1;
    int b = 0, e = 0;
    for (int d = 2; d <= n; ++d) {
      for (int i = 0; i+d <=n ; ++i) {
        int j = i+d-1;
        if (s[i] != s[j])
          len[i][j] = 0;
        else {
          if (i + 1 > j - 1)
            len[i][j] = 2;
          else if (len[i+1][j-1] != 0)
            len[i][j] = len[i+1][j-1] + 2;
          else
            len[i][j] = 0;
        }

        if (len[i][j] > maxlen) {
          maxlen = len[i][j];
          b = i;
          e = j;
        }
      }
    } // for
    return s.substr(b, e-b+1);
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