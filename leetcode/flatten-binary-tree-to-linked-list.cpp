// there is a very elegant code, but I do not understand
// http://oj.leetcode.com/discuss/637/can-you-improve-upon-my-recursive-approach
#include "leetcode.h"

class Solution {
public:
  void flatten(TreeNode *root) {
    dfs(root);
  }

  TreeNode *dfs(TreeNode *root) {
    if (root == NULL) return NULL;

    if (root->left == NULL && root->right == NULL)
      return root;

    TreeNode *ll = dfs(root->left);
    TreeNode *lr = dfs(root->right);

    if (root->left != NULL) {
      ll->right = root->right;
      root->right = root->left;
      root->left = NULL;
    }

    if (lr != NULL)
      return lr;
    else
      return ll;
  }
};

void print_right_child(TreeNode *root) {
  while (root != NULL) {
    printf("%d ", root->val);
    root = root->right;
  }
  printf("\n");
}

int main() {
  string tree = "1 2 3 # # 4 # # 5 # 6 # #";
  TreeNode *root = deserialize_tree(tree);
  Solution sol;
  preorder_cout(root);
  sol.flatten(root);
  preorder_cout(root);
  print_right_child(root);
  
  return 0;
}