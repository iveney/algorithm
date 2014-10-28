#include <iostream>
// #include <string>
using namespace std;

int main() {
  int T; 
  long long N;
  cin >> T;
  for (int i = 0; i < T; ++i)
  {
    cin >> N;
    long long result;
    if (N % 2 == 0)
      result = (N+1)*(N/2) + 1;
    else
      result = (N+1)/2 * N + 1;
    cout << result % 1000000000 << endl;
  }
  return 0;
}