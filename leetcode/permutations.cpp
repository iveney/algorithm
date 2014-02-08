#include <iterator>
#include "leetcode.h"

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
      vector<vector<int> > result;
      if (num.size() == 1) {
        result.push_back(num);
        return result;
      }

      for (size_t i = 0; i < num.size(); ++i ) {
        vector<int> rest;
        for(size_t j = 0; j < num.size(); ++j) {
          if (j != i) rest.push_back(num[j]);
        }

        auto partial = permute(rest);
        for(auto it = partial.begin(); it != partial.end(); it++) {
          // note: inserting to front of vector is inefficient
          // only for the sake of matching the OJ's answer order
          it->insert(it->begin(), num[i]);
          result.push_back(*it);
        }
      }
      return result;
    }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  int A[] = {1, 2, 3};
  int n = sizeof(A) / sizeof(int);
  vector<int> num(A, A + n);
  auto result = sol.permute(num);
  for (auto row : result) {
    copy(row.begin(), row.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';
  }
  return 0;
}