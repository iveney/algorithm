// http://leetcode.com/2011/07/lowest-common-ancestor-of-a-binary-tree-part-i.html
#include "leetcode.h"

class Solution {
public:
  int count = 0;
  TreeNode *LCA(TreeNode *root, TreeNode *p, TreeNode *q) {
    ++count;
    if (root == nullptr) return nullptr;
    if (root == p || root == q) return root; // root is in the path
    TreeNode *L = LCA(root->left, p, q);
    TreeNode *R = LCA(root->right, p, q);
    if (L && R) return root; // p, q at both sides
    return L? L : R; // p, q at either side, or not found
  }
};

int main() {
  Solution sol;
  TreeNode *root = deserialize_tree(string("1 2 4 # # 5 # # 3 # #"));
  TreeNode *p = root->left->left;
  // TreeNode *q = root->right;
  // TreeNode *q = root->left->right;
  TreeNode *q = root->left;
  TreeNode *lca = sol.LCA(root, p, q);
  cout << lca->val << " count: " << sol.count << "\n";
  
  return 0;
}