#include <vector>
using std::vector;

#include "levenshtein_distance.h"

size_t levenshtein_distance(const string &a, const string &b) {
  int na = a.size();
  int nb = b.size();
  vector<vector<int> > D(na + 1, vector<int>(nb + 1, 0));

  for (int j = 0; j <= nb; ++j) {D[0][j] = j; }
  for (int i = 0; i <= na; ++i) {D[i][0] = i; }
  for (int i = 1; i <= na; ++i) {
    for (int j = 1; j <= nb; ++j) {
      if (a[i-1] != b[j-1]) {
        D[i][j] = std::min({D[i-1][j], D[i][j-1], D[i-1][j-1]});
      } else {
        D[i][j] = D[i-1][j-1];
      }
    }
  }
  return D[na][nb];
}
