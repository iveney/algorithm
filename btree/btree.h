#ifndef _BTREE_H_
#define _BTREE_H_

#include <string>
using std::string;

// for simplicity, use typedef instead of template
typedef int Key;
typedef string Value;

// using knuth's definition: order = # number of children
// then the tree is containing maximum (order-1) keys, 
// and minimum (order-1)/2 keys
const int order = 5;

namespace BTree{
  class Node{
    Node(): parent(NULL) {
      for (int i = 0; i < order; i++) {
        child[i] = NULL;
      }
    }
    Node *parent;
    Node *child[order];
    Key key[order-1];
    Value value[order-1];
  };

  class BTree{
    BTree():root(NULL){};
    Node *root;
  };
}

#endif /* end of include guard: _BTREE_H_ */
