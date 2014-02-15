// this one is tricky, should practice again

#include "leetcode.h"

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
      if (root == NULL) return false;

      return hasPathSum_recursive(root, sum);
    }

    bool hasPathSum_recursive(TreeNode *root, int sum) {
      // if (root == NULL) {
      //   return sum == 0;
      // }

      if (root->left == NULL && root->right == NULL) {
        // it's a leaf node
        return sum == root->val;
      }

      bool result = false;
      if (root->left != NULL) {
        result = hasPathSum_recursive(root->left, sum - root->val);
        if (result) return true;
      }
      
      if (root->right != NULL) {
        result = hasPathSum_recursive(root->right, sum - root->val);
      }

      return result;
    }
};

int main(int argc, char const *argv[])
{
  string tree("5 4 11 7 # # 2 # # # 8 13 # # 4 # 1 # #");
  TreeNode* root = deserialize_tree(tree);
  preorder_cout(root);

  Solution sol;
  cout << sol.hasPathSum(NULL, 0) << endl;
  return 0;
}