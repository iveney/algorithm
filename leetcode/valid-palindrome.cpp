#include <cctype>
#include "leetcode.h"

class Solution {
public:
  bool isPalindrome(string s) {
    if (s.empty()) return true;

    int n = s.size();
    int i = 0, j = n - 1;
    while (i <= j) {
      if (!isalnum(s[i])) {
        ++i;
        continue;
      }
      if (!isalnum(s[j])) {
        --j;
        continue;
      }
      if (tolower(s[i]) != tolower(s[j]))
        return false;

      ++i;
      --j;
    }

    return true;
  }
};

int main() {
  Solution sol;
  vector<string> str {
    "A man, a plan, a canal: Panama",
    "",
    "a",
    ".",
    ".a",
    "a.a",
    "race a car"
  };

  for (auto &s : str) {
    cout << sol.isPalindrome(s) << '\n';
  }
  
  return 0;
}