// lca in tree with parent pointer
// http://leetcode.com/2011/07/lowest-common-ancestor-of-a-binary-tree-part-ii.html

// basic idea is to locate both nodes and their height h1, h2, say h1-h2 = d
// we can then find the parent when (h1-d) , h2 meets

#include "leetcode.h"

class Solution {
public:
  int hp, hq;
  void find_height(TreeNodeWithParent *root, TreeNodeWithParent *p, TreeNodeWithParent *q, int height) {
    if (root == nullptr) return;
    if (hp >= 0 && hq >= 0) return;

    if (root == p) {
      hp = height;
    }
    if (root == q) {
      hq = height;
    }
    find_height(root->left, p, q, height+1);
    find_height(root->right, p, q, height+1);
  }

  TreeNodeWithParent *LCA(TreeNodeWithParent *root, TreeNodeWithParent *p, TreeNodeWithParent *q) {
    if (!root || !p || !q) return nullptr;
    hp = hq = -1;
    find_height(root, p, q, 0);

    // p or q is not in the tree
    if (hp < 0 || hq < 0) return nullptr;

    // make sure hp <= hq
    if (hp > hq) {
      swap(hp, hq);
      swap(p, q);
    }
    // move q to the same height as p
    int d = hq - hp;
    while (d > 0) {
      --d;
      q = q->parent;
    }

    while (q != p) {
      p = p->parent;
      q = q->parent;
    }
    return p;
  }
};


int main() {
  Solution sol;
  TreeNode *node = deserialize_tree(string("1 2 4 # # 5 # # 3 # #"));
  TreeNodeWithParent *root = TreeNodeWithParent::fromTreeNode(node);
  // TreeNodeWithParent *p = root->right;
  TreeNodeWithParent *p = root->left->left;
  TreeNodeWithParent *q = root->left->right;
  // TreeNodeWithParent *q = root->left;
  TreeNodeWithParent *lca = sol.LCA(root, p, q);
  cout << lca->val << "\n";
  
  return 0;
}