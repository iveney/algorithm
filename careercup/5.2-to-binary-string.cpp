#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

string to_binary_string(string &num) {
  string binary;
  int decimal = num.find(".");
  int integral = atoi(num.substr(0, decimal).c_str());
  double fraction = atof(num.substr(decimal, num.size() - decimal).c_str());

  // integral portion
  int p = 1;
  while ((p << 1) <= integral) {
    p <<= 1;
  }
  while (p > 0) {
    if (integral - p >= 0) {
      binary.push_back('1');
      integral -= p;
    } else {
      binary.push_back('0');
    }
    p >>= 1;
  }

  binary.push_back('.');

  // fraction portion
  int i = 0;
  while (1) {
    if (i++ > 32)
      return string("ERROR");

    fraction *= 2;
    if ( abs(fraction - 1.0) <= 1e-6 ) {
      binary.push_back('1');
      break;
    }
    else if (fraction > 1) {
      binary.push_back('1');
      fraction -= 1;
    } else {
      binary.push_back('0');
    }
  }

  return binary;
}

int main(int argc, char const *argv[])
{
  string num = "1023.875";
  string binary = to_binary_string(num);
  cout << binary << endl;
  return 0;
}