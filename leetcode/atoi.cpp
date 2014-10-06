#include <cctype>
#include "leetcode.h"

class Solution {
public:
  int atoi(const char *str) {
    int num = 0;
    if (str == NULL) {
      return 0;
    }

    // remove trailing space
    int i = 0;
    while (str[i] != 0 && isspace(str[i])) ++i;

    int sign = 0;
    while (str[i] != 0) {
      // ending space
      if (isspace(str[i]))
        break;

      // only handle the first appearance of sign
      if (str[i] == '+') {
        if (sign == 0) {
          sign = 1;
        } else {
          break;
        }
      } else if (str[i] == '-') {
        if (sign == 0) {
          sign = -1;
        } else {
          break;
        }
      } else if (!isdigit(str[i])) {
        break;
      } else {
        long long int tmp = num;
        tmp = tmp * 10 + (str[i] - '0');
        // overflow
        if (sign >= 0 && tmp > numeric_limits<int>::max()) {
          return numeric_limits<int>::max();
        } else if (sign < 0 && -tmp < numeric_limits<int>::lowest()) {
          return numeric_limits<int>::lowest();
        }
        num = tmp;
      }
      ++i;
    }

    if (sign != 0)
      return sign * num;

    return num;
  }
};

int main() {
  vector<string> strs = {
    // "  234  ",
    // "  +234  ",
    // "  -234  ",
    // "  -23+4  ",
    // "  3e12",
    // ".9",
    // "ab90cd ",
    // "3.54",
    // "++123",
    // "-+13",
    // "62 43 10",
    // "       0x1e  1",
    // "",
    // "0",
    // "00000123",
    "10522545459",
    "1932610867",
    "2147483647",
    "2147483648",
    "-2147483647",
    "-2147483648",
    "4294967296",
    "-4294967296",
  };
  Solution sol;
  for (auto &str : strs) {
    cout << atoi(str.c_str()) << endl;
    cout << sol.atoi(str.c_str()) << endl << endl;
  }
  
  return 0;
}