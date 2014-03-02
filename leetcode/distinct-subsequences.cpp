#include "leetcode.h"

class Solution {
public:
  int numDistinct(string S, string T) {
    int n = S.size();
    int m = T.size();
    if (n == 0 || m == 0 || m > n) return 0;

    vector<int> pre(n+1, 1), cur(n+1, 1);

    // copy(pre.begin(), pre.end(), ostream_iterator<int>(cout, " "));
    // cout << '\n';
    for (int i = 1; i <= m; ++i) {
      for (int j = i; j <= n; ++j) {
        if (j > i)
          cur[j] = cur[j-1];
        else
          cur[j] = 0;
        if (S[j-1] == T[i-1]) {
          cur[j] += pre[j-1];
        }
      } // for j
      pre = cur;
    // copy(pre.begin(), pre.end(), ostream_iterator<int>(cout, " "));
    // cout << '\n';
    } // for i

    return cur[n];
  }
};

int main() {
  Solution sol;
  vector<string> S {
    "rabbbit",
    "ABCABC",
    "A",
    "",
    "A",
    "A",
    "fff",
    "fffd",
  };
  vector<string> T {
    "rabbit",
    "ABC",
    "A",
    "A",
    "",
    "B",
    "ffff",
    "ffff",
  };

  for (int i = 0; i < S.size(); ++i) {
    printf("%d\n", sol.numDistinct(S[i], T[i]));
  }
  
  return 0;
}