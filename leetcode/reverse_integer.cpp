#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
      int negative = x < 0 ? (-1) : 1;
      if (negative == -1)
        x = -x;
      int c = 0;
      while ( x > 0 ) {
        int r = x % 10;
        c = c * 10 + r;
        x = x / 10;
      }
      return negative * c;
    }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  cout << sol.reverse(123) << endl;
  cout << sol.reverse(-123) << endl;
  cout << sol.reverse(0) << endl;
  cout << sol.reverse(-0) << endl;
  return 0;
}