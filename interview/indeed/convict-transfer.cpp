#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<vector<int> > parse_input() {
  vector<vector<int> > graph;
  int n = 0; // num inmates
  int m = 0; // num pairs
  cin >> n >> m;
  graph.resize(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  return graph;
}

int compute_price(const vector<vector<int> > &graph) {
  int total = 0;
  int n = graph.size() - 1;
  vector<bool> visited(n + 1, false);
  for (int i = 1; i <= n; ++i) {
    if (visited[i]) {
      continue;
    }

    int component_size = 0;
    queue<int> q;
    q.push(i);

    while (!q.empty()) {
      int j = q.front();
      q.pop();
      ++component_size;
      visited[j] = true;
      for (int nbr : graph[j]) {
        if (visited[nbr]) {
          continue;
        }
        visited[nbr] = true;
        q.push(nbr);
      }
    }

    total += ceil(sqrt(component_size));
  }

  return total;
}

int main(int argc, char const *argv[])
{
  auto graph = parse_input();
  cout << compute_price(graph);
  return 0;
}