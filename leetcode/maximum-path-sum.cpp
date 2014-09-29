#include "leetcode.h"

class Solution {
  int maxSum_;
public:
  int maxPathSumFromRoot(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }

    int leftSum = maxPathSumFromRoot(root->left);
    int rightSum = maxPathSumFromRoot(root->right);

    // using root
    int sumFromRoot = max({
      root->val,
      root->val + leftSum,
      root->val + rightSum});

    // use or not use root
    maxSum_ = max({
      maxSum_,
      sumFromRoot,
      root->val + leftSum + rightSum});
    return sumFromRoot;
  }

  int maxPathSum(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }

    maxSum_ = root->val;
    maxPathSumFromRoot(root);
    return maxSum_;
  }
};

int main() {
  // TreeNode *root = deserialize_tree(string("-2 2 1 # # 3 # # -3 # #"));
  // TreeNode *root = deserialize_tree(string("1 2 # # 3 # #"));
  TreeNode *root = deserialize_tree(string("-3 # #"));
  Solution sol;
  cout << sol.maxPathSum(root) << endl;
  
  return 0;
}