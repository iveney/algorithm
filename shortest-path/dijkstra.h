#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__

#include <vector>
using namespace std;

void dijkstra(
  const vector<vector<int> > &graph,
  vector<int> &dist,
  vector<int> &path) {
  // assume 0 = s, n-1 = t
  int n = graph.size();
  dist.assign(n, numeric_limits<int>::max());
  path.assign(n, -1);
  vector<bool> visited(n, false);
  dist[0] = 0;

  // execute n times (visit n vertices)
  for (int i = 0; i < n; ++i) {
    // find the vertices that is closest to visited set
    // this can be implemented using priority queue
    int minj = -1;
    int mind = numeric_limits<int>::max();
    for (int j = 0; j < n; ++j) {
      if (visited[j]) continue;
      if (dist[j] < mind) {
        mind = dist[j];
        minj = j;
      }
    }

    visited[minj] = true;
    // update the distance from minj to its adj neighbors
    for (int j = 0; j < n; ++j) {
      if (!visited[j] &&
          graph[minj][j] != -1 &&
          dist[j] > dist[minj] + graph[minj][j]) {
        // update path to i as s->minj->j
        dist[j] = dist[minj] + graph[minj][j];
        path[j] = minj;
      }
    }
  }
}

#endif
