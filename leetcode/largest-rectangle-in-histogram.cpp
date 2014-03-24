// Really nice solution. Need to think about it again
#include <stack>
#include "leetcode.h"

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