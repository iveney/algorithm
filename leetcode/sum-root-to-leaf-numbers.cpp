// interesting question. practice again
#include "leetcode.h"

class SolutionV2 {
public:
  int total;
  int sumNumbers(TreeNode *root) {
    total = 0;
    sumRecursive(root, 0);
    return total;
  }

  void sumRecursive(TreeNode *root, int carry) {
    if (root == NULL) {
      return;
    }

    int sum = carry * 10 + root->val;
    if (root->left == NULL && root->right == NULL) {
      total += sum;
      return;
    }

    sumRecursive(root->left, sum);
    sumRecursive(root->right, sum);
  }
};

class Solution {
public:
    int sumNumbers(TreeNode *root) {
      return sumNumbers(root, 0);
    }

    int sumNumbers(TreeNode *root, int pre) {
      if (root == NULL) return 0;

      int np = pre + root->val;
      
      if (root->left == NULL && root->right == NULL)
        return np;

      np *= 10;

      return sumNumbers(root->left, np) + sumNumbers(root->right, np);
    }
};

int main(int argc, char const *argv[])
{
  // string serialized_tree("3 9 # # 2 1 # 8 4 # # # 7 # #");
  // string serialized_tree("1 2 # # 3 # #");
  // string serialized_tree("0 1 # # 2 # #");
  // string serialized_tree("1 2 4 # # 5 # # 3 # # ");
  string serialized_tree("1 2 3 # # #");
  TreeNode *root = deserialize_tree(serialized_tree);
  Solution sol;
  cout << sol.sumNumbers(root) << endl;

  return 0;
}