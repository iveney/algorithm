#ifndef __BELLMANFORD_H__
#define __BELLMANFORD_H__

#include <vector>
#include <limits>
using std::vector;
using std::numeric_limits;

#include "graph.hpp"


bool bellman_ford(
  const Graph &G,
  vector<int> &dist,
  vector<int> &pred) {

  int N = num_vertices(G);
  dist.assign(N, numeric_limits<int>::max());
  dist[0] = 0;
  pred.assign(N, -1);

  IndexMap index = get(vertex_index, G);
  auto weight = get(edge_weight, G);
  graph_traits<Graph>::edge_iterator ei, ei_end;
  for (int i = 0; i < N - 1; ++i) {
    for (boost::tie(ei, ei_end) = edges(G); ei != ei_end; ++ei) {
      int u = index[source(*ei, G)];
      int v = index[target(*ei, G)];
      if (dist[u] != numeric_limits<int>::max() &&
          get(weight, *ei) + dist[u] < dist[v]) {
        dist[v]  = get(weight, *ei) + dist[u];
        pred[v] = u;
      }
    }
  }

  for (boost::tie(ei, ei_end) = edges(G); ei != ei_end; ++ei) {
    int u = index[source(*ei, G)];
    int v = index[target(*ei, G)];
    if (get(weight, *ei) + dist[u] < dist[v]) {
      return false;
    }
  }
  
  return true;
}

#endif
