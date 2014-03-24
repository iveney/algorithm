#include "leetcode.h"

class Solution {
public:
  string convert(string s, int nRows) {
    if (s == "" || nRows == 1) return s;

    vector<string> rows(nRows);

    int r = 0;
    int dir = 1;
    for (int i = 0; i < s.size(); ++i) {
      rows[r].push_back(s[i]);
      r += dir;
      if (r == nRows-1 || r == 0)
        dir *= -1;
    }

    string result;
    for (auto &s : rows) {
      result += s;
    }

    return result;
  }
};

int main() {
  Solution sol;
  vector<string> str {
    "PAYPALISHIRING",
    "P",
    "",
  };

  for (auto s : str) {
    for (int i = 1; i <= s.size()+5; ++i) {
      printf("%d : %s\n", i, sol.convert(s, i).c_str());
    }
  }


  return 0;
}