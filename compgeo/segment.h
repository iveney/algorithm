#ifndef _SEGMENT_H_

#define _SEGMENT_H_

#include "point.h"

namespace compgeom {

struct Segment {
  Segment(Point ss, Point tt): s(ss), t(tt){}
  Point s, t;
};

}

#endif /* end of include guard: _SEGMENT_H_ */
