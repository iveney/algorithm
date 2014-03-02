// hard problem, need to think again
#include <limits>
#include "leetcode.h"

class Solution {
  int found;
  TreeNode *wrong[2];
public:
  void recoverTree(TreeNode *root) {
    found = 0;
    recoverTree(root, NULL);
  }

  void recoverTree(TreeNode *root, TreeNode *parent) {
    if (root == NULL || found == 2) return;

    if (parent != NULL && 
        ((parent->left == root  && root->val > parent->val) ||
         (parent->right == root && root->val < parent->val)) ) {
      wrong[found++] = root;
      if (found == 2) {
        swap(wrong[0]->val, wrong[1]->val);
      }
    } else {
      recoverTree(root->left, root);
      // cout << root->val << ' ';
      recoverTree(root->right, root);
    }
  }
};

int main() {
  Solution sol;
  string tree = "50 30 20 10 # # # 40 # # 90 70 60 # # 80 # # 100 # #";
  TreeNode *root = deserialize_tree(tree);
  // level_order_cout(root);

  // swap(root->left->val, root->right->val);
  // swap(root->val, root->right->left->val);
  // swap(root->val, root->right->val);
  // swap(root->val, root->left->val);
  swap(root->val, root->right->left->right->val);
  // level_order_cout(root);
  inorder_cout(root);

  sol.recoverTree(root);
  inorder_cout(root);
  // level_order_cout(root);
  
  return 0;
}