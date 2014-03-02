#include <bitset>
#include <iostream>
using namespace std;

const int width = 32;

// assume i j is valid
void set_bits(int &N, int M, int i, int j){
  int low = (1 << (i+1)) - 1;
  int high = ~((1 << (j+1)) - 1);
  int mask = low | high;
  N = (N & mask) | (M << i);
}

int main(int argc, char const *argv[]) {
  int N = 0b10000000000;
  int M = 0b10101;
  int i = 7, j = 11;
  cout << bitset<width> (N) << endl;
  cout << bitset<width> (M) << endl;
  set_bits(N, M, i, j);
  cout << bitset<width> (N) << endl;
  return 0;
}