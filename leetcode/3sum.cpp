#include "leetcode.h"
#include "array2D.hpp"

class SolutionV2 {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
    int n = num.size();
    vector<vector<int> > result;
    if (n < 3) return result;

    sort(num.begin(), num.end());
    for (int i = 0; i < n - 2; ++i) {
      if (i > 0 && num[i] == num[i-1]) {
        continue;
      }
      if (num[i] > 0) {
        break;
      }
      for (int j = i + 1; j < n - 1; ++j) {
        if (j-1 != i && num [j] == num[j-1]) {
          continue;
        }
        if (num[i] + num[j] > 0) {
          break;
        }
        for (int k = j + 1; k < n; ++k) {
          int sum = num[i]+num[j]+num[k];
          if (sum > 0) {
            break;
          }
          if (k-1 != j && num[k] == num[k-1]) {
            continue;
          }
          if (sum == 0) {
            result.push_back(vector<int>{num[i],num[j],num[k]});
          }
        }// k
      }// j
    }// i
      
    return result;
  }
};

class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > result;
    sort(num.begin(), num.end());
    int n = num.size();
    for (int i = 0; i < n-2; ++i) {
      // we are done
      if (num[i] > 0) return result;

      // avoid duplicate
      if (i > 0 && num[i] == num[i-1])
        continue;

      int j = i+1, k = n-1;
      while (j < k) {
        int sum = num[i] + num[j] + num[k];
        if (sum > 0)
          --k;
        else if (sum < 0)
          ++j;
        else {
          vector<int> v{num[i], num[j], num[k]};
          if (result.empty() || result.back() != v)
            result.push_back(v);
          ++j;
          --k;
        }
      } // while
    } // for
    return result;
  }
};

int main() {
  Solution sol;
  vector<vector<int> > S {
    // {-1,0,1,2,-1,-4},
    {-1,0, -1, -1, 0, 0, 1, 1, 1},
  };

  for (auto &s : S) {
    auto result = sol.threeSum(s);
    print_2D<int> (result);
  }
  
  return 0;
}