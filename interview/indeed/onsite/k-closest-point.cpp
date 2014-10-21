// Given a set of points, find k points that are closest to a given point

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
  double x, y;
};

ostream & operator << (ostream & os, const Point &p) {
  return os << "(" << p.x << ", " << p.y << ")";
}

double euclid(const Point& lhs, const Point& rhs) {
  double dx = lhs.x - rhs.x;
  double dy = lhs.y - rhs.y;
  return (dx*dx + dy*dy);
}

namespace std {
template <>
class less<Point> {
public:
  less(const Point& t = Point({0, 0})) : target(t) {}
  bool operator() (const Point& lhs, const Point& rhs) {
    return euclid(lhs, target) < euclid(rhs, target);
  }
  Point target;
};
}

// Use a heap/priority queue to maintain k min points
// Runtime: nlog(k)
vector<Point> k_closest_heap(const vector<Point> &points,
                             const Point & target, int k) {
  vector<Point> q;
  auto closer_to_target = std::less<Point>(target);
  for (auto p : points) {
    if (q.size() < k || closer_to_target(p, q.front()) ) {
      if (q.size() == k) {
        pop_heap(q.begin(), q.end(), closer_to_target);
        q.pop_back();
      }
      q.push_back(p);
      push_heap(q.begin(), q.end(), closer_to_target);
    }
  }
  return q;
}

// find the kth element, anything before it in the random access container
// will be sorted
// Runtime: approximately O(n)
vector<Point> k_closest(const vector<Point> &points,
                        const Point &target, int k) {
  vector<Point> result(points);
  auto closer_to_target = std::less<Point>(target);
  nth_element(result.begin(), result.begin() + k, result.end(), closer_to_target);
  result.resize(k);
  return result;
}

int main(int argc, char const *argv[])
{
  vector<Point> points {
    {1, 1},
    {2, 3},
    {4, 6},
    {0, 0},
    {6, 2},
    {-1, 3},
    {-2, -5},
    {-1, -3},
  };
  Point target {-10, 10};
  int k = 4;
  auto r1 = k_closest_heap(points, target, k);
  auto r2 = k_closest(points, target, k);
  copy(r1.begin(), r1.end(),
    ostream_iterator<decltype(r1)::value_type>(cout, "\n"));
  cout << "\n";
  copy(r2.begin(), r2.end(),
    ostream_iterator<decltype(r2)::value_type>(cout, "\n"));
  return 0;
}