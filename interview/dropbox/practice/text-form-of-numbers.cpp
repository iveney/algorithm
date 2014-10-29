#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  string convert(int num) {
    vector<vector<string> > eng {
      {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight",
       "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
       "sixteen", "seventeen", "eighteen", "nighteen",},
      {"zero", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy",
       "eighty", "nighty",},
    };
    if (num == 1000) {
      return string("one thousand");
    }

    string s;
    int hundred = num / 100;
    if (hundred > 0) {
      s += eng[0][hundred] + " hundred";
    }
    num %= 100;
    if (num == 0) {
      return s;
    } else if (!s.empty()) {
      s += " and ";
    }

    if (num < 20) { // 1 - 19
      s += eng[0][num];
    } else { // 20 - 99
      int ten = num / 10;
      if (ten > 0) { // 20, 30, ..., 90
        s += eng[1][ten];
      }
      num %= 10;
      if (num > 0) {
        s += " " + eng[0][num];
      }
    }
    return s;
  }
};

int main(int argc, char const *argv[])
{
  vector<int> tests = {
    1, 2, 3, 10, 11, 20, 30,
    100, 105, 110, 156,
    260,
    984,
    1000,
  };
  Solution sol;
  for (auto i : tests) {
    cout << i << " -> " << sol.convert(i) << "\n";
  }
  return 0;
}