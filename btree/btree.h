#ifndef _BTREE_H_
#define _BTREE_H_

#include <vector>
using std::vector;

// using knuth's definition: ORDER = # number of children
// then the tree is containing maximum (ORDER-1) keys, 
// and minimum (ORDER-1)/2 keys
const int ORDER = 4;

class Btree{
public:
  Btree(): parent(NULL) {
    // data.resize(ORDER-1);
    children.resize(ORDER);
  }

  void insert(int value);
  Btree* find(int value);

  static void insert_node(Btree *node);

  bool full() const {return data.size() == ORDER - 1;}
  //void remove(int value);

  vector<int> data;
  Btree *parent;
  vector<Btree *> children;
};

void dump_graphviz(Btree* root);

#endif /* end of include guard: _BTREE_H_ */
