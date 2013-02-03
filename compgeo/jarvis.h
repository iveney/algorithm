#ifndef _JARVIS_H_
#define _JARVIS_H_

#include "point.h"

namespace compgeom {

int jarvis(Point *pts, Point *output, int n) {
  // trivial cases: 0, 1, 2
  int i;
  if (n <= 2) {
    for (i = 0; i < n; i++) {
      output[i] = pts[i];
    }
    return n;
  }

  // find the left most point
  int l = 0;
  for (i = 1; i < n; i++) {
    if (pts[i].x < pts[l].x) {
      l = i;
    }
  }

  int count = 0;
  int p = l, q;
  do {
    q = (p + 1) % n;

    // find the next point
    for (i = 1; i < n; i++) {
      if (is_counter_clockwise(pts[p], pts[i], pts[q])) {
        q = i;
      }
    }

    output[count++] = pts[q];
    p = q;
  } while (p != l);

  return count;
}

}

#endif /* end of include guard: _JARVIS_H_ */
