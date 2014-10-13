#include "leetcode.h"

class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();
    if (n == 0) return 0;

    vector<int> D(n+1, 0);
    if (s[0] < '1' || s[0] > '9') {
      return 0;
    }
    D[0] = D[1] = 1;
    for (int i = 1; i < n; ++i) {
      int j = i + 1;
      int num = (s[i-1] - '0') * 10 + (s[i] - '0');

      if (num == 0) {
        // 00
        return 0;
      } else if (num >= 1 && num <= 26) {
        if (s[i] == '0') { // 10, 20
          D[j] = D[j-2];
        }
        else if (s[i-1] == '0') { // 01..09
          D[j] = D[j-1];
        } else { // 11-19, 21-26
          D[j] = D[j-1] + D[j-2];
        }
      } else {
        if (s[i] == '0') { // 30, 40, ...
          return 0;
        } else {
          // >= 27
          D[j] = D[j-1];
        }
      }
    } // for

    return D[n];
  }
};

int main() {
  vector<string> ss = {
    "1221",
    "12",
    "0",
    "",
    "0123",
    "1201",
    "1200",
    "230",
  };
  Solution sol;
  for (auto &s : ss) {
    cout << sol.numDecodings(s) << endl;
  }
  
  return 0;
}