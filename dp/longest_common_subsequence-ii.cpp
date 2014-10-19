// practice of longest common subsequence

#include <iostream>
#include <vector>
using namespace std;

int longest_common_subsequence(const string &a, const string &b) {
  if (a.empty() || b.empty()) return 0;

  int m = a.size();
  int n = b.size();
  vector<vector<int>> D(m+1,vector<int>(n+1, 0));
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      char ca = a[i-1];
      char cb = b[j-1];
      D[i][j] = max(D[i-1][j], D[i][j-1]);
      if (ca != cb) {
        D[i][j] = max(D[i][j], D[i-1][j-1]);
      } else {
        D[i][j] = max(D[i][j], D[i-1][j-1] + 1);
      }
    }
  }
  return D[m][n];
}

int main(int argc, char const *argv[])
{
  string a, b;
  while (cin >> a >> b) {
    cout << longest_common_subsequence(a, b) << "\n";
  }

  return 0;
}