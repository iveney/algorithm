#include <iostream>
#include "basic.h"
#include "jarvis.h"
#include "graham.h"
#include "sweep_hull.h"
using namespace std;
using namespace compgeom;

int main(int argc, const char *argv[])
{
  Point pts[] = {
    Point(3, 6),
    Point(4, 0),
    Point(5, 4),
    Point(6, 5),
    Point(4, 7),
    Point(1, 5),
  };
  int n = sizeof(pts) / sizeof(Point);
  Point *output = new Point[n];
  int count = jarvis(pts, output, n);
  for (int i = 0; i < count; i++) {
    cout << " " << output[i];
  }
  cout << endl;

  count = graham(pts, output, n);
  for (int i = 0; i < count; i++) {
    cout << " " << output[i];
  }
  cout << endl;

  int *next = new int[n];
  int *prev = new int[n];
  count = sweep_hull(pts, n, next, prev);
  for (int i = 0, j = 0; i < count; i++, j = next[j]) {
    cout << " " << pts[j];
  }
  cout << endl;

  delete []output;
  delete []prev;
  delete []next;
  return 0;
}
