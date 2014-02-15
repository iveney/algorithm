// rule can be found here
// http://www.onlineconversion.com/roman_numerals_advanced.htm
#include "leetcode.h"

class Solution {
  int getnum(char C) {
    int d = 0;
    char c = toupper(C);
    switch (c) {
    case 'I':
      d = 1;
      break;
    case 'V':
      d = 5;
      break;
    case 'X':
      d = 10;
      break;
    case 'L':
      d = 50;
      break;
    case 'C':
      d = 100;
      break;
    case 'D':
      d = 500;
      break;
    case 'M':
      d = 1000;
      break;
    default:
      break;
    }
    return d;
  }
public:
  int romanToInt(string s) {
    int v = 0;
    int p = 0, q = -1;
    for (char c : s) {
      p = getnum(c);
      if (q != -1 && p > q) {
        v -= q;
        v += p - q;
        q = -1;
      } else {
        v += p;
        q = p;
      }
    }
    return v;
  }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  string s("IC");
  cout << sol.romanToInt(s) << endl;
  return 0;
}