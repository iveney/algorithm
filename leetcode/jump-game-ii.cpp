// still confusing
// http://oj.leetcode.com/discuss/422/is-there-better-solution-for-jump-game-ii
#include <limits>
#include <iterator>
#include "leetcode.h"

class Solution {
public:
  int jump(int A[], int n) {
    if (n <= 1) return 0;

    int last = 0;
    int curr = 0;
    int step = 0;
    for (int i = 0; i < n; ++i) {
      if (i > last) {
        if (curr == last && last < )
      } 
    }
    return M[n-1];
  }
};

int main() {
  Solution sol;
  vector<vector<int> > A {
    {2,3,1,1,4},
    {5, 1, 1, 1, 3, 1, 1, 1,},
  };

  for (auto v : A) {
    printf("%d\n", sol.jump(v.data(), v.size()));
  }

  
  return 0;
}