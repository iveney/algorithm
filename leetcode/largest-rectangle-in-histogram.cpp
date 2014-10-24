// Really nice solution. Need to think about it again
#include <stack>
#include "leetcode.h"

// really hard to think about we can use a stack here
// observation: the rectangle is defined by some height[i],
// a right boundaries which has smaller height than height[i], and a left boundary which has a height no larger height than height[i]
// this means we should search for some i where height[i] < height[i-1] as the right boundary, and find the corresponding left boundary
// the left boundary is defined as the first j such that height[j] <= height[i]
//              0  1  2  3  4
// say, we have 1, 2, 5, 5, 3, i = 4
// we then look for the rectangle defined by 5 5 3, where the latter 5 is the top, the first 5 is left boundary and 3 is right boundary
// we can use a stack to achieve this by pushing the non-decreasing sequence of height
// note that we pop out the stack to continue the area computation, i is not moved after we compute 5 5 3, which means the right boundary is still 3, 
// but the top becomes the first 5, left boundary becomes 2, so the rectangle is defined by 2 5 5 3
// 
// alternatively, we can think of each time we encounter some i where height[i] < height[i-1], we trigger the area computation event
class Solution {
public:
  int largestRectangleArea(vector<int> &height) {
    int n = height.size();
    if(n == 0) return 0;

    int maxarea = 0;
    int i = 0;
    stack<int> p;
    // p.push_back(i++);
    while (i < n) {
      if (p.empty() || height[i] >= height[p.top()]) {
        p.push(i++);
      } else {
        int tp = p.top();
        p.pop();

        int width = p.empty() ? i : (i - p.top() - 1);
        int area = height[tp] * width;
        if (area > maxarea)
          maxarea = area;
      }
    } // while

    // compute the remaining heights
    while ( !p.empty() ) {
      int tp = p.top();
      p.pop();

      int width = p.empty() ? i : (i - p.top() - 1);
      int area = height[tp] * width;
      if (area > maxarea)
        maxarea = area;
    }

    return maxarea;
  }
};

int main() {
  Solution sol;
  vector<int> height{2,1,5,6,2,3};
  cout << sol.largestRectangleArea(height) << endl;
  
  return 0;
}