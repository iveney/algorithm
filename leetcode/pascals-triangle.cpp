#include <iostream>
#include <vector>
using namespace std;

void output(vector<vector<int> > &result) {
  for (auto row : result) {
    for (auto i : row) {
      cout << i << " ";
    }
    cout << endl;
  }
}

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
      vector<vector<int> > result(numRows);
      if (numRows == 0) return result;
      result[0].push_back(1);
      for (int r = 1; r < numRows; r++) {
        int n = r + 1;
        result[r].resize(n);
        for (int i = 0; i < n; i++) {
          int ll = ((i - 1) >= 0) ? (result[r-1][i-1]) : 0;
          int rr = (i < r) ? (result[r-1][i]) : 0;
          result[r][i] = ll + rr;
        }
      }
      return result;
    }
};


int main(int argc, char const *argv[])
{
  int numRows = 10;
  Solution sol;
  auto result = sol.generate(numRows);
  output(result);

  return 0;
}