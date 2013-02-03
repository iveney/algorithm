#ifndef QUADTREE_X5BFPQGD

#define QUADTREE_X5BFPQGD

#include <vector>
using namespace std;

class Point {
 public:
  Point(double x, double y): x_(x), y_(y) {}
  double x_, y_;
};

class Box {
 public:
  Box(Point center, double half_width, double half_height):
      center_(center), half_width_(half_width), half_height_(half_height) {}
  Point center_;
  double half_width_, half_height_;

  bool containsPoint(const Point &pt) const{
    return (pt.x_ >= center_.x_ - half_width_) &&
           (pt.x_ <= center_.x_ + half_width_) &&
           (pt.y_ >= center_.y_ - half_height_) &&
           (pt.y_ <= center_.y_ + half_height_);
  }
};

const int MAX_POINTS = 4;
class QuadTree {
 public:
  QuadTree(const Box &box) : box_(box){}
  ~QuadTree() {deleteSelf();}

  bool insertPoint(const Point &pt);
  vector<Point> queryRange(const Box &range);

  vector<Point> plist_;
  Box box_;

  QuadTree* NW_;
  QuadTree* NE_;
  QuadTree* SW_;
  QuadTree* SE_;

 private:
  void deleteSelf();
  void splitSelf();
};

#endif /* end of include guard: QUADTREE_X5BFPQGD */
