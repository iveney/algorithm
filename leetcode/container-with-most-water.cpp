#include "leetcode.h"

class Solution {
public:
  int maxArea(vector<int> &height) {
    int i = 0, j = height.size() - 1;
    int max_area = 0;
    while (i < j) {
      max_area = std::max(max_area, min(height[i], height[j]) * (j-i));
      if ( height[i] < height[j] ) {
        i++;
      } else {
        j--;
      }
    }

    return max_area;
  }
};

int main() {
  // vector<int> height = {2, 1, 3, 5, 1, 4, 2, 6};
  vector<int> height = {};
  Solution sol;
  cout << sol.maxArea(height) << '\n';
  
  return 0;
}