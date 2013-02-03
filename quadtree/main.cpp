#include <iostream>
using namespace std;

#include "quadtree.h"

int main(int argc, const char *argv[])
{
  Point zero(0,0);
  Box box(zero, 50, 50);
  Point pts[] = {Point(10, 10),
                 Point(20, 20),
                 Point(-10, -40),
                 Point(-10, 35),
                 Point(15, -20),
                 Point(-5, 25),
                 Point(30, -40)
  };

  QuadTree* tree = new QuadTree(box);

  int numPoints = sizeof(pts) / sizeof(Point);
  for (int i = 0; i < numPoints; ++i)
    tree->insertPoint(pts[i]);

  cout << "Insert center x, y, half width, half height: " ;
  double x, y, hw, hh;
  cin >> x >> y >> hw >> hh;
  vector<Point> ret = tree->queryRange(Box(Point(x, y), hw, hh));

  for (int i = 0; i < ret.size(); i++) {
    cout << " (" << ret[i].x_ << ", " << ret[i].y_ << ")";
  }
  cout << endl;

  delete tree;
  return 0;
}
