#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
  const int MAX_BUFFER = 100;
  int L[MAX_BUFFER][MAX_BUFFER] = {0};

  string A="ABDABC";
  string B="ABEABC";
  cout << "Enter A: " << endl;
  cin >> A;
  cout << "Enter B: " << endl;
  cin >> B;
  int N = A.size();
  int M = B.size();
  int max_len = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = 0;j <= M; ++j) {
      if (A[i-1] == B[j-1]) {
        L[i][j] = L[i-1][j-1] + 1;
      } else
        L[i][j] = 0;
      if (L[i][j] > max_len)
        max_len = L[i][j];
    }
  }
  cout << max_len << endl;

  return 0;
}
