#include "leetcode.h"

class Solution {
public:
  int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<int> pre(m+1), cur(m+1);
    // initialize (empty string to word 2)
    for (int j = 0; j <= m; ++j) {
      pre[j] = j;
      cur[j] = j;
    }

    for (int i = 1; i <= n; ++i) {
      // initialize (word 1 to empty string)
      cur[0] = i;
      for (int j = 1; j <= m; ++j) {
        if (word1[i-1] == word2[j-1]) {
          cur[j] = pre[j-1];
        } else {
          cur[j] = 1 + std::min({pre[j-1], pre[j], cur[j-1]});
        }
      }
      pre = cur;
    } // for i

    return cur[m];
  }
};

int main() {
  Solution sol;
  vector<string> word1 {
    "lime",
    "ABCDEF",
    "LEET",
    "",
    "abbb",
    "",
  };
  vector<string> word2 {
    "plie",
    "ACE",
    "CODER",
    "a",
    "",
    "",
  };
  for (int i = 0; i < word1.size(); ++i) {
    printf("%s -> %s : %d\n", word1[i].c_str(), word2[i].c_str(),
      sol.minDistance(word1[i], word2[i]));
  }
  
  return 0;
}