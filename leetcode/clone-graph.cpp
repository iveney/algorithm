#include <queue>
#include <unordered_map>
#include "leetcode.h"

class Solution {
  std::unordered_map<int, UndirectedGraphNode *> clone;
  std::unordered_set<int> visited;
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == NULL) return NULL;
    std::queue<UndirectedGraphNode *> myqueue;
    myqueue.push(node);

    while ( !myqueue.empty() ) {
      UndirectedGraphNode *p = myqueue.front();
      myqueue.pop();

      // already visited this node
      if ( visited.find(p->label) != visited.end() )
        continue;

      visited.insert(p->label);
      UndirectedGraphNode *cur = clone[p->label];

      if (cur == NULL)
        cur = clone[p->label] = new UndirectedGraphNode(p->label);

      for (auto nbr : p->neighbors) {
        UndirectedGraphNode *clone_nbr = clone[nbr->label];

        if (clone_nbr == NULL) {
          clone_nbr = clone[nbr->label] = new UndirectedGraphNode(nbr->label);
        }

        if ( visited.find(nbr->label) == visited.end() )
          myqueue.push(nbr);

        cur->neighbors.push_back(clone_nbr);
      }
    } // while

    return clone[node->label];
  }
};

int main() {
  Solution sol;
  string graph = "0,1,2#1,2#2,2";
  UndirectedGraphNode *node = deserialize_graph(graph);
  serialize_graph(cout, node);

  auto nn = sol.cloneGraph(node);
  serialize_graph(cout, nn);

  return 0;
}