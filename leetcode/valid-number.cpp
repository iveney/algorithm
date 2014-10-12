#include <cassert>
#include "leetcode.h"

class Solution {
public:
  bool isNumber(const char *s) {
    if (s == NULL) {
      return false;
    }

    // remove starting space
    while(*s != 0 && isspace(*s)) {
      ++s;
    }

    enum State{UNINITIALIZED, BASE, DOT, FLOAT, EXP, ORDER};
    State state = UNINITIALIZED;
    int sign = 0;
    while(*s != 0) {
      char c = *s;
      if (isspace(c)) {
        break;
      } else if (c == '+') {
        if (sign != 0 || (state != UNINITIALIZED && state != EXP)) {
          return false;
        }
        sign = 1;
      } else if (c == '-') {
        if (sign != 0 || (state != UNINITIALIZED && state != EXP)) {
          return false;
        }
        sign = -1;
      } else if (c == 'e' || c == 'E') {
        // base should exist before 'e'
        // 'e' should appear only once
        if (state == UNINITIALIZED || state == DOT || state >= EXP) {
          return false;
        }
        state = EXP;

        // we allow '+' and '-' in exp, reset the sign
        sign = 0;
      } else if (c == '.') {
        // '.' should appear only once
        // '.' should not appear in EXP
        // '.' should be preceded or followed by a number

        // if (state == DOT || state == FLOAT || state == EXP || state == ORDER) {
        if (state > BASE) {
          return false;
        }

        if (state == UNINITIALIZED) {
          state = DOT;
        } else if (state == BASE) {
          state = FLOAT;
        }
      } else if (!isdigit(c)) {
        return false;
      } else {
        // it's a digit
        if (state == UNINITIALIZED) {
          state = BASE;
        } else if (state == DOT) {
          state = FLOAT;
        } else if (state == EXP) {
          state = ORDER;
        }
      }
      // cout << "state change : " << state << endl;
      ++s;
    } // while

    // remove trailing space
    while(*s != 0 && isspace(*s)) {
      ++s;
    }

    // trailing non-space characters: invalid
    if (*s != 0) {
      return false;
    }

    // number must be initialized and cannot be intermediate state
    if (state == UNINITIALIZED || state == DOT || state == EXP) {
      return false;
    }

    return true;
  }
};

int main() {
  vector<string> nums {
    "0",
    " 0.1 ",
    "abc",
    "1 a",
    "2e10",
    "+2e10",
    "-2.512E12",
    "  0.1 1",
    "123.45e123.5",
    "++52 ",
    "-+ 14",
    "1234a",
    "e123",
    "   ",
    "",
    ".",  // false
    ".1", // true
    "1.", // true
    "1.e10", // true
    ".15e-10", // true
    ".15e+-10", // false
    "1e", // false
    "2e0", // true
    ".e1",
    "6+1",
    "-1.",
    "92e1740e91",
  };
  vector<bool> result{
    1,
    1,
    0,
    0,
    1,
    1,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    1,
    1,
    1,
    0,
    0,
    1,
    0,
    0,
    1,
    0, 
  };
  Solution sol;
  for (int i = 0; i < nums.size(); ++i) {
    const char *str = nums[i].c_str();
    bool output = sol.isNumber(str);
    printf("'%s' : %d\n", str, output);
    assert(output == result[i]);
  }
  
  return 0;
}