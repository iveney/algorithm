// lca in bst
// http://leetcode.com/2011/07/lowest-common-ancestor-of-a-binary-search-tree.html

#include "leetcode.h"

class Solution {
public:
  TreeNode *find(TreeNode *root, TreeNode *node) {
    if (!root || !node) return nullptr;
    if (root == node) return root;

    return (root->val < node->val)? find(root->right, node) : find(root->left, node);
  }

  TreeNode *LCA(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || !p || !q) return nullptr;
    if (root == p || root == q) return root;
    if ((root->val < p->val && root->val > q->val) ||
        (root->val > p->val && root->val < q->val)) {
      // make sure the two nodes are in the tree
      TreeNode *fp = find(root, p);
      TreeNode *fq = find(root, q);
      return (fp && fq)? root : nullptr;
    } else if (root->val > max(p->val, q->val)) {
      return LCA(root->left, p, q);
    } else if (root->val < min(p->val, q->val)) {
      return LCA(root->right, p, q);
    } else {
      // should not arrive here
      return nullptr;
    }
  }
};

//      _______6______
//     /              \
//  ___2__          ___8__
// /      \        /      \
// 0      _4       7       9
//       /  \
//       3   5


int main() {
  Solution sol;
  TreeNode *root = deserialize_tree(string("6 2 0 # # 4 3 # # 5 # # 8 7 # # 9 # #"));
  TreeNode *lca;
  lca = sol.LCA(root, root->left->right->left /* 3 */, root->right->right /* 9 */);
  cout << lca->val << "\n";
  lca = sol.LCA(root, root->left->right->left /* 3 */, root->left->left /* 0 */);
  cout << lca->val << "\n";
  lca = sol.LCA(root, root->left /* 2 */, root->left->left /* 0 */);
  cout << lca->val << "\n";

  return 0;
}