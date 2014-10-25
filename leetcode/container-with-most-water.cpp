// interesting idea
#include "leetcode.h"

// Key observation: the shorter boundary decides the area.
// The only way that we can increase the area is to make the shorter boundary taller
// If we fix right boundary and change left, those with a smaller value must be useless
// that gives us two directions: 
// - move left bound to left: we need to consider all as the width is increasing
// - move left bound to right: we only need to consider the taller boundary as the width is decreasing, so this is a better choice
// 
// A good visualization: https://oj.leetcode.com/discuss/11482/yet-another-way-to-see-what-happens-in-the-o-n-algorithm

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