// idea is easy, implementation is hard, need to practice again
#include <limits>
#include "leetcode.h"

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
    friend bool operator == (const Point &lhs, const Point & rhs);
};

bool operator == (const Point &lhs, const Point & rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

class Solution {
public:
  int maxPoints(vector<Point> &points) {
    int n = points.size();
    if (n <= 2) return n;

    unordered_map<double, int> lines;
    int globalMax = 0;

    for (int i = 0; i < n; ++i) {
      lines.clear();
      int dup = 0;
      int currentMax = 0;
      Point & p = points[i];
      for (int j = i+1; j < n; ++j) {
        Point & q = points[j];

        if (p == q) {
          ++dup;
          continue;
        }

        double slope;
        if (p.x == q.x) {
          slope = numeric_limits<double>::infinity();
        } else {
          slope = 1.0 * (q.y - p.y) / (q.x - p.x);
        }
        auto &ct = lines[slope];
        ++ct;
        if (ct > currentMax)
          currentMax = ct;
      } // for j

      currentMax += dup + 1;
      if (currentMax > globalMax)
        globalMax = currentMax;

    } // for i

    return globalMax;
  }
};

int main() {
  vector<Point> points {
    {1, 1},
    {2, 2},
    {3, 3},
    {4, 4},
    {5, 5},
    {6, 6},
    {2, 1},
    {3, 2},
    {3, 8},
    {7, 4},
    {2, 5},
    {9, 6},
  };

  // vector<Point> points {
    // {1, 1}, {0, 0}, {1, 1},
   // {3,1},{12,3},{3,1},{-6,-1},
   // {3,1},{3,1},{3,1},{3,1},{3,1},{3,1}
  // };
  Solution sol;
  int currentMax = sol.maxPoints(points);
  cout << currentMax << endl;
  
  return 0;
}