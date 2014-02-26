#include "../leetcode/leetcode.h"

class TreeParentNode {
public:
  TreeParentNode(int x = 0) : val(x), left(NULL), right(NULL), parent(NULL) {};

  int val;
  TreeParentNode *left, *right, *parent;
};

TreeParentNode *inorder_next(TreeParentNode *node) {
  if (node == NULL) return NULL;

  // case 1 : right subtree not empty
  if (node->right != NULL) {
    TreeParentNode *p = node;
    p = p->right;

    while (p->left != NULL)
      p = p->left;

    return p;
  }

  // case 2 : right subtree empty
  TreeParentNode *parent = node->parent;
  TreeParentNode *p = node;
  while (parent != NULL) {
    if (parent->left == p)
      return parent;
    p = parent;
    parent = p->parent;
  }

  return NULL;
}

int main(int argc, char const *argv[])
{
  TreeParentNode nodes[9];
  for (int i = 1; i <= 8; ++i) {
    nodes[i].val = i;
  }

  nodes[1].left = &nodes[2];
  nodes[1].right = &nodes[3];
  nodes[2].parent = nodes[3].parent = &nodes[1];

  nodes[2].left = &nodes[4];
  nodes[2].right = &nodes[5];
  nodes[4].parent = nodes[5].parent = &nodes[2];

  nodes[4].left = &nodes[6];
  nodes[6].parent = &nodes[4];

  nodes[5].right = &nodes[7];
  nodes[7].parent = &nodes[5];

  nodes[3].left = &nodes[8];
  nodes[8].parent = &nodes[3];

  TreeParentNode *root = &nodes[1];

  for (TreeParentNode &node : nodes) {
    TreeParentNode *next = inorder_next(&node) ;
    cout << node.val  << ": " << (next ? next->val : NULL) << '\n';
  }
  return 0;
}