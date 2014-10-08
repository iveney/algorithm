#include <iostream>
#include "dijkstra.h"

void test_dijkstra(const vector<vector<int> > &graph) {
  cout << "Testing Dijkstra algorithm\n";
  vector<int> dist, path;
  dijkstra(graph, dist, path);

  copy(dist.begin(), dist.end(), 
    ostream_iterator<decltype(dist)::value_type>(cout, " "));
  cout << '\n';
  copy(path.begin(), path.end(), 
    ostream_iterator<decltype(path)::value_type>(cout, " "));
  cout << "\n\n";
}

int main() {
  vector<vector<int> > graph {
    { 0,  5,  2, -1, -1, -1},
    { 5,  0,  4,  3,  2, -1},
    { 2, -1,  0,  3,  7, -1},
    {-1, -1, -1,  0,  1,  2},
    {-1, -1,  7,  1,  0,  5},
    {-1, -1, -1,  2,  5,  0},
  };

  test_dijkstra(graph);
  return 0;
}