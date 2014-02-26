// think about how to avoid duplicate
// 1. carefully avoid same prefix/postfix
// 2. use hashmap/sorting before insert
#include "leetcode.h"
#include "array2D.hpp"

// bug: how to prevent duplicate?
class Solution {
public:
  vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int> > result;
    if (num.size() < 4) return result;

    sort(num.begin(), num.end());
    for (int i = 0; i < num.size(); ++i) {
      if (i > 0 && num[i] == num[i-1])
        continue;
      for (int j = num.size()-1; j >=0; --j) {
        if (j < num.size() - 1 && num[j] == num[j+1])
          continue;
        int sum = num[i] + num[j];
        int k = i+1, l =j-1;

        while (k < l) {
          int s = sum + num[k] + num[l];
          if (s == target) {
            vector<int> quad = {num[i], num[k], num[l], num[j],};
            if (result.empty() || quad != result.back())
              result.push_back(quad);
            ++k;
            --l;
          } else if (s < target) {
            ++k;
          } else {
            --l;
          }
        } // while
      } // for j
    } // for i

    return result;
  }
};

int main() {
  Solution sol;
  // vector<int> num = {1,0,-1,0,-2,2};
  // vector<int> num = {-3,-2,-1,0,0,1,2,3};
  // vector<int> num = {-5,-4,-3,-2,-1,0,0,1,2,3,4,5};
  vector<int> num = {-5,-3,-2,0,0,4,4,5};
  // vector<int> num = {-5,-5,-4,-3,-2,-1,0,0,1,2,3,4,5,5};
  int target = 4;
  auto result = sol.fourSum(num, target);
  print_2D<int>(result);
  cout << result.size();
  
  return 0;
}