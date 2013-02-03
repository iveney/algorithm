#ifndef _GRAHAM_H_

#define _GRAHAM_H_

#include "point.h"

namespace compgeom {

int graham(Point *pts, Point *output, int n) {
  // trivial cases: 0, 1, 2
  int i;
  if (n <= 2) {
    for (i = 0; i < n; i++) {
      output[i] = pts[i];
    }
    return n;
  }
  // now guarantee to have at least 3 points

  // sort the array as counter-clockwise
  make_counter_clockwise(pts, n);

  // now pts[0] is left-most point
  int l = 0;
  int p = l, q = l + 1, r = l + 2;
  output[0] = pts[p];
  output[1] = pts[q];
  int count = 2;

  do {
    if (is_counter_clockwise(pts[p], pts[q], pts[r])) {
      output[count++] = pts[r];
      p = q;
      q = r;
      r = (r + 1) % n;
    }
    else {
      // remove q (previously r)
      --count;
      q = p;
      p = (p - 1) < 0? n - 1: p - 1;
    }
  } while (r != l);

  return count;
}

}

#endif /* end of include guard: _GRAHAM_H_ */
