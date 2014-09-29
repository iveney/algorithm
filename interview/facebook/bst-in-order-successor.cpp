#include "../../leetcode/leetcode.h"


class Solution {
  TreeNode *pred;
  TreeNode *succ;
public:
  TreeNode *in_order_successor(TreeNode *root, int val) {
    pred = succ = NULL;
    in_order_traverse(root, val);
    return succ;
  }

  void in_order_traverse(TreeNode *root, int val) {
    if (root == NULL || succ != NULL) return;

    in_order_traverse(root->left, val);
    if (pred != NULL && pred->val == val) {
      succ = root;
    }

    pred = root;
    in_order_traverse(root->right, val);
  }
};


int main(int argc, char const *argv[]) {
  string tree = "50 30 20 10 # # # 40 # # 90 70 60 # # 80 # # 100 # #";
  stringstream sstream(tree);
  TreeNode *root = deserialize_tree(tree);
  inorder_cout(root);
  Solution sol;
  string token;
  while (sstream >> token) {
    if (token == "#") continue;
    int val = atoi(token.c_str());
    TreeNode *succ = sol.in_order_successor(root, val);
    if (succ != NULL)
      cout << "Next of " << val << " : " << succ->val << endl;
  }
  return 0;
}