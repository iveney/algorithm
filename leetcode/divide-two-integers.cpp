#include <limits>
#include <cmath>
#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
  int divide(int dividend, int divisor) {
    bool positive = ((dividend >= 0 && divisor >= 0) || (dividend < 0 && divisor < 0));

    // overflow
    unsigned int residue = dividend;
    if (dividend < 0) residue = -residue;

    unsigned int div = divisor;
    if (divisor < 0) div = -div;

    int q = 0;

    while (residue >= div) {
      long int part = div;
      long int counter = 1;
      while ( (part<<1) > 0 && (part<<1) < residue) {
        part <<= 1;
        counter <<= 1;
      }
      q += counter;
      residue -= part;
    }
    return positive? q : -q;
  }
};

int main() {
  // int dividend = std::numeric_limits<int>::max();
  // int divisor = 2;
  // int dividend = -1010369383;
  // int dividend = -2147483648;
  // int divisor  = -2147483648;
  int dividend = 1;
  int divisor  = -1;
  Solution sol;
  cout << dividend / divisor << endl;
  cout << sol.divide(dividend, divisor) << endl;
  
  return 0;
}