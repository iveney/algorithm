#include <iostream>
#include <type_traits>
#include "graph.hpp"
#include "dijkstra.h"
#include "bellman-ford.h"

void output_result(const vector<int> &dist, const vector<int> &pred) {
  copy(dist.begin(), dist.end(), 
    ostream_iterator<int>(cout, " "));
  cout << '\n';
  copy(pred.begin(), pred.end(), 
    ostream_iterator<int>(cout, " "));
  cout << "\n\n";
}

void test_dijkstra(const vector<vector<int> > &graph) {
  cout << "Testing Dijkstra algorithm\n";
  vector<int> dist, pred;
  dijkstra(graph, dist, pred);
  output_result(dist, pred);
}

void test_bellmanford(const Graph& G) {
  cout << "Testing Bellman-Ford algorithm\n";
  vector<int> dist, pred;
  bool result = bellman_ford(G, dist, pred);
  if (result) {
    output_result(dist, pred);
  } else {
    cerr << "Negative cycle detected.\n";
  }
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

  enum {s, x, y, z, t, N};
  const int num_vertices = N;
  const char* name = "sxyzt";
  Edge edges[] = {
    Edge(s, t), Edge(s, y),
    Edge(t, x), Edge(t, y), Edge(t, z),
    Edge(x, t),
    Edge(y, x), Edge(y, z),
    Edge(z, s), Edge(z, x),
  };
  const int num_edges = sizeof(edges)/sizeof(edges[0]);
  int weights[] = {
    6, 7,
    5, 8, -4,
    -2,
    -3, 9,
    2, 7,
  };
  Graph G(edges, edges + num_edges, weights, num_vertices);

  // test_dijkstra(graph);
  test_bellmanford(G);
  return 0;
}