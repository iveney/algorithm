#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

pair<int, int> longest_common_substring(const string &a, const string &b) {
  int m = a.size(), n = b.size();
  int mlen = 0, endi = -1;
  vector<vector<int>> D(m+1, vector<int>(n+1,0));
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      D[i][j] = 0;
      if (a[i-1] == b[j-1]) {
        D[i][j] = D[i-1][j-1] + 1;
      }
      if (D[i][j] > mlen) {
        mlen = D[i][j];
        endi = i;
      }
    }
  }
  return make_pair(endi-mlen, mlen);
}

int main(int argc, char const *argv[])
{
  string a, b;
  while(cin>>a>>b) {
    int len, i;
    tie(i, len) = longest_common_substring(a, b);
    cout << len << "\n";
    if (len) {
      cout << a.substr(i, len) << "\n";
    }
  }
  return 0;
}