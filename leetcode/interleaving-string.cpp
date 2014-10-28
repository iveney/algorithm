// interesting DP solution
#include "leetcode.h"

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {  
    if (s1.size() + s2.size() != s3.size()) return false;

    vector<vector<bool>> ans(s1.size() + 1, vector<bool>(s2.size()+1));

    for (int i = 0; i <= s1.size(); ++i) {
      for (int j = 0; j <= s2.size(); ++j) {
        if (i == 0 && j == 0) {
          // all empty string
          ans[i][j] = true;
        } else if (i == 0) {
          // interleave only from s2
          ans[i][j] = ans[i][j-1] && s2[j-1] == s3[j-1];
        } else if (j == 0) {
          // interleave only from s1
          ans[i][j] = ans[i-1][j] && s1[i-1] == s3[i-1];
        } else {
          // either from s1 or s2
          ans[i][j] = (ans[i-1][j] && s1[i-1] == s3[i+j-1]) ||
                      (ans[i][j-1] && s2[j-1] == s3[i+j-1]);
        }
      } // j
    } // i

    return ans[s1.size()][s2.size()];
  }
};

class SolutionNaive {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.empty() && s2.empty() && s3.empty()) {
      return true;
    }
    if (s3.empty()) {
      // one of s1 and s2 is not empty
      return false;
    }

    if (s1[0] == s3[0]) {
      string s11 = s1.substr(1, s1.size());
      string s33 = s3.substr(1, s3.size());
      bool result = isInterleave(s11, s2, s33);
      if (result) return true;
    }

    if (s2[0] == s3[0]) {
      string s22 = s2.substr(1, s2.size());
      string s33 = s3.substr(1, s3.size());
      bool result = isInterleave(s1, s22, s33);
      if (result) return true;
    }
    return false;
  }
};

// This is wrong
class SolutionWrong {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int i, j, k, p, q;
    i = j = k = p = q = 0;
    while (k < s3.size()) {
      if (i < s1.size() && j < s2.size() &&
          s1[i] == s3[k] && s2[j] == s3[k]) {
        // p, q remains
        ++i;
        ++j;
        ++k;
      } else if (i < s1.size() && s1[i] == s3[k]) {
        if (j != q) {
          j = q;
        } else {
          ++i;
          ++k;
        }
        p = i;
      } else if (j < s2.size() && s2[j] == s3[k]) {
        if (i != p) {
          i = p;
        } else {
          ++j;
          ++k;
        }
        q = j;
      } else {
        // no match
        return false;
      }
    }
    if (i == s1.size() && j == s2.size() && k == s3.size()) {
      return true;
    }
    return false;
  }
};

int main() {
  // vector<string> s3s {
  //   "aadbbcbcac",
  //   "aadbbbaccc",
  // };
  // string s1 = "aabcc";
  // string s2 = "dbbca";
  string s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
  string s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
  string s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
  // string s1 = "aa";
  // string s2 = "ab";
  // string s3 = "aaba";
  Solution sol;
  // for (auto &s3 : s3s) {
    cout << sol.isInterleave(s1, s2, s3) << "\n";
  // }
   
  return 0;
}