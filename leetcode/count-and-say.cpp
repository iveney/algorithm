#include "leetcode.h"

class Solution {
public:
  string countAndSay(int n) {
    if (n==1) return "1";
    string s("11");
    for (int i = 3; i <= n; ++i) {
      string old = s;
      s.clear();
      char c = old[0];
      int count = 1;
      int j = 1;
      while (1) {
        if (j >= old.size() || old[j] != c) {
          s += to_string(count) + c;

          if (j >= old.size())
            break;

          c = old[j];
          count = 1;
        } else {
          ++count;
        }
        ++j;
      } // while
    }
    return s;
  }
};

int main() {
  Solution sol;
  int n = 10;
  for (int i = 1; i <= n; i++) {
    cout << sol.countAndSay(i) << endl;
  }
  
  return 0;
}