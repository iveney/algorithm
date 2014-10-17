// very elegant DP O(n^2) solution
#include "leetcode.h"

class Solution {
public:
  int minCut(string s) {
    int n = s.size();
    if (n == 0) return 0;
    // this records if s[i..j] is a palindrome
    // optimal substructure:
    // ispal[i][j] is true if s[i] == s[j] && ispal[i+1][j-1] == true
    vector<vector<bool> > ispal(n, vector<bool>(n, false));

    // this records the minCut for s[i..n-1], so d[0] is the solution
    // optimal substructure:
    // d[i] = min{d[j+1]+1 where s[i][j] is a palindrome, i.e., ispal[i][j] == true}
    vector<int> d(n, 0);

    for (int i = n - 2; i >= 0; --i) {
      ispal[i][i] = true;
      d[i] = d[i+1] + 1; // initialize to the trivial case (cut between i|i+1)
      for (int j = i + 1; j < n; ++j) {
        // s[i .. j] is palindrome
        if (s[i] == s[j] && (i+1 >= j-1 || ispal[i+1][j-1])) {
          ispal[i][j] = true;

          // s[i..n-1] itself is palindrome, set to 0
          if (j == n-1) {
            d[i] = 0;
          } else if (d[i] > 1 + d[j+1]) {
            d[i] = 1 + d[j+1];
          }
        }
      } // for j
    } // for i
    return d[0];
  }
};

int main() {
  vector<string> cases = {
    "aab",
    "",
    "a",
    "aa",
    "aaaaaa",
    "baab",
    "baaba",
  };
  Solution sol;
  for (auto &s : cases) {
    cout << sol.minCut(s) << "\n";
  }
  
  return 0;
}