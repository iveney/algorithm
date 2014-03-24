#include <bitset>
#include <iostream>
using namespace std;

int nbits(int A, int B) {
  int bits = A^B;
  bitset<32> b(bits);
  return b.count();
}

int main(int argc, char const *argv[])
{
  cout << nbits(31, 1<<2) << '\n';
  return 0;
}