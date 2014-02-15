#include "leetcode.h"

class Solution {
public:
    int lengthOfLastWord(const char *s) {
      int prev = 0, len = 0;
      int i = 0;
      char c;
      while ( (c = s[i]) != 0) {
        if ( c == ' ' ) {
          if (len > 0)
            prev = len;
          len = 0;
        }
        else
          ++len;

        ++i;
      }

      if (s[i-1] == ' ')
        return prev;

      return len;
    }
};

int main(int argc, char const *argv[])
{
  const char *str[] = {
    "Hello world",
    " hello",
    "hello ",
    "",
    " ",
    " A",
    "A        ",
    "  A        ",
    "ABC  A        ",
    "A  ABC        ",
  };
  Solution sol;
  for (auto s : str) {
    cout << sol.lengthOfLastWord(s) << " : '" << s << "'" << endl;
  }

  return 0;
}