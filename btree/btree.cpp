#include "btree.h"

void dump_graphviz(Btree* root) {
  if (root == NULL) return;

}

void Btree::insert_node(Btree *node, int value) {
  data.push_back(value);
  if (node->data.size() < ORDER - 1) {
  } else {
    // split
    int mid = (ORDER-1) / 2;
    Btree *left = new Btree();
    Btree *right = new Btree();

    left->data.assign(node->data.begin(), node->data.begin() + mid);
    left->children.assign(
      node->children.begin(), node->children.begin() + mid + 1);

    right->data.assign(node->data.begin() + mid + 1, node->data.end());
    right->children.assign(
      node->children.begin() + mid + 1, node->children.end());

    // push the middle element to q's parent
    if (node->parent != NULL && !node->parent->full()) {
      node->parent->push_back(value);
    }
    Btree::insert_node(q->parent, node->data[mid]);
  }
}

void Btree::insert(int value) {
  if (data.empty()) {
    data.push_back(value);
    return;
  }

  // search for a node to insert (top-down)
  Btree *p = this, *q = this;
  while(p != NULL) {
    int i = 0;
    while (i < p->data.size() && value < p->data[i]) {
      ++i;
    }

    if (i == p->data.size() && value < p->data.back()) {
      --i;
    }

    q = p;
    p = p->children[i];
  }

  // q is the node to insert value
  Btree::insert_node(q, value);
}