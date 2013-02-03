#ifndef _BASIC_H_

#define _BASIC_H_

#include <algorithm>
using std::sort;
#include "point.h"
#include "segment.h"
#include "vector.h"

namespace compgeom {

inline bool is_counter_clockwise(Point p, Point q, Point r) {
  Vector pq(p, q), pr(p, r);
  int prod = cross_product(pq, pr);
  return prod > 0;
}

static Point _ccw_l;
bool ccw_wrt_l(const Point &p, const Point &q) {
  if (_ccw_l == p) return true;
  else if (_ccw_l == q) return false;

  return is_counter_clockwise(_ccw_l, p, q);
}

inline void make_counter_clockwise(Point *pts, int n) {
  // find the left most point
  int l = 0;
  for (int i = 1; i < n; i++) {
    if (pts[i].x < pts[l].x) {
      l = i;
    }
  }

  // sort the array according to l
  _ccw_l = pts[l];
  sort(pts, pts + n, ccw_wrt_l);
}

}

#endif /* end of include guard: _BASIC_H_ */
