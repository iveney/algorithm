#include "leetcode.h"

class Solution {
public:
    vector<int> grayCode(int n) {
      vector<int> result;
      result.push_back(0);
      if (n == 0) return result;

      result.push_back(1);

      for (int i = 1; i < n; ++i) {
        vector<int> tmp(result);
        // copy result in reverse order
        copy(tmp.rbegin(), tmp.rend(), back_inserter(result));
        // first half remain the same
        // set bit 2^i to 1 in the later half
        int size = result.size();
        for (int j = size/2; j < size; j++) {
          result[j] |= 1 << i;
        }
      }
      return result;
    }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  auto result = sol.grayCode(2);
  copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
  cout << '\n';
  return 0;
}