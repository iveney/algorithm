#ifndef _POINT_H_

#define _POINT_H_

#include <iostream>
using std::ostream;

namespace compgeom {

struct Point {
  Point(int xx = 0, int yy = 0): x(xx), y(yy) {}
  int x, y;
  bool operator == (const Point &rhs) { return x == rhs.x && y == rhs.y; }
  friend ostream & operator << (ostream &os, const Point &p);
};

bool compare_x(const Point &p, const Point &q) {
  return p.x < q.x;
}

inline ostream & operator << (ostream &os, const Point &p) {
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}

}

#endif /* end of include guard: _POINT_H_ */
