#include "leetcode.h"

class Solution {
public:
    string intToRoman(int num) {
      string tens[] = {"I", "X", "C", "M"};
      string fives[] = {"V", "L", "D"};
      int i = 0;
      string val;
      while (num != 0) {
        int d = num % 10;
        num /= 10;

        if (d == 9) {
          val = tens[i] + tens[i+1] + val;
        } else if ( 5 <= d && d <= 8 ) {
          string ii;
          for (int j = 1; j <= d - 5; ++j) {
            ii += tens[i];
          }
          val = fives[i] + ii + val;
        } else if ( d == 4 ) {
          val = tens[i] + fives[i] + val;
        } else if ( 1 <= d && d <= 3 ) {
          string ii;
          for (int j = 1; j <= d ; ++j) {
            ii += tens[i];
          }
          val = ii + val;
        } else {
          // 0 : do nothing
        }
        ++i;
      }
      return val;
    }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  cout << sol.intToRoman(3999) << endl;
  cout << sol.intToRoman(1234) << endl;
  cout << sol.intToRoman(4) << endl;
  cout << sol.intToRoman(3987) << endl;

  return 0;
}