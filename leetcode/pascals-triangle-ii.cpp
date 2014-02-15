#include "leetcode.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
      vector<int> pre, cur;
      vector<int> *p = &cur, *q = &pre;
      pre.push_back(1);

      for (int i = 1; i <= rowIndex; ++i) {
        p->resize(i+1);
        (*p)[0] = (*p)[i] = 1;
        for (int j = 1; j < i ; ++j) {
          (*p)[j] = (*q)[j-1] + (*q)[j];
        }
        swap(p, q);
      }
      return *q;
    }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  int rowId = 10;
  auto result = sol.getRow(rowId);
  copy(result.begin(), result.end(), 
    ostream_iterator<decltype(result)::value_type>(cout, " "));
  cout << '\n';
  return 0;
}