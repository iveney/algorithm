#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <utility>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
using namespace boost;

typedef adjacency_list<vecS, vecS, directedS,
                       no_property, property<edge_weight_t, int> > Graph;
typedef std::pair<int, int> Edge;
typedef property_map<Graph, vertex_index_t>::type IndexMap;
typedef property_map<Graph, edge_weight_t>::type EdgeWeightMap;

#endif
