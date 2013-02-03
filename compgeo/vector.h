#ifndef _VECTOR_H__
#define _VECTOR_H__

namespace compgeom {

struct Vector {
    Vector(Point s, Point t) {
          x = t.x - s.x;
              y = t.y - s.y;
                }
      int x, y;

};

inline int cross_product(Vector &v1, Vector &v2) {
    return v1.x * v2.y - v1.y * v2.x;
}


}

#endif /* end of include guard: _VECTOR_H__ */
