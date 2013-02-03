#ifndef _SWEEP_HULL_H_
#define _SWEEP_HULL_H_

#include <algorithm>
using std::sort;

namespace compgeom {

int sweep_hull(Point *pts, int n, int *next, int *prev) {
  // sort according to x-coordinate
  sort(pts, pts + n, compare_x);
  next[0] = 1; prev[1] = 0;
  next[1] = 0; prev[0] = 1;
  int count = 2;

  for (int i = 2; i < n; i++) {
    if (pts[i].y > pts[i - 1].y) {
      prev[i] = i - 1;
      next[i] = next[i - 1];
    }
    else{
      next[i] = i - 1;
      prev[i] = prev[i - 1];
    }

    next[prev[i]] = i;
    prev[next[i]] = i;

    count++;

    // remove concave points
    while (is_counter_clockwise(pts[i], pts[prev[i]], pts[prev[prev[i]]])) {
      next[prev[prev[i]]] = i;
      prev[i] = prev[prev[i]];
      count--;
    }

    while (is_counter_clockwise(pts[i], pts[next[next[i]]], pts[next[i]])) {
      prev[next[next[i]]] = i;
      next[i] = next[next[i]];
      count--;
    }
  } // end of for
  return count;
}

} /* compgeom */

#endif /* end of include guard: _SWEEP_HULL_H_ */
