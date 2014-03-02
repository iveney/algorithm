#include <vector>
#include <iostream>
using namespace std;

int find_missing(vector<int> &A) {
  int n = A.size();
  int nbits = sizeof(int) * 8;
  int sum = n * (n + 1) / 2;
  for (int i = 0; i < n; ++i) {
    int x = A[i];
    for (int j = 0; j < nbits; ++j) {
      int b = (x>>j) & 1;
      sum -= b * (1<<j);
    }
  }
  return sum;
}

int main() {
  int n = 30;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    A[i] = i;
  }
  A.erase(A.begin()+29);
  copy(A.begin(), A.end(), 
    ostream_iterator<decltype(A)::value_type>(cout, " "));
  cout << '\n';

  int miss = find_missing(A);
  cout << miss << endl;

  return 0;
}