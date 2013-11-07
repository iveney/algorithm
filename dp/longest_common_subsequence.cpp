#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
  const int MAX_BUFFER = 100;
  int D[MAX_BUFFER][MAX_BUFFER] = {0};
  string A, B;
  cout << "Enter A:" << endl;
  cin >> A;
  cout << "Enter B:" << endl;
  cin >> B;

  int N = A.size(), M = B.size();

  for (int i = 1; i <= N; ++i) {
    for (int j = 1;j <= M; ++j) {

      D[i][j] = max(D[i-1][j], D[i][j-1]);
      if (A[i-1] == B[j-1]) 
        D[i][j] = max(D[i][j], D[i-1][j-1] + 1);
    }
  }

  cout << D[N][M] << endl;
  return 0;
}
