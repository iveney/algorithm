#include <limits>
#include "leetcode.h"

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    int low = numeric_limits<int>::min();
    int high = numeric_limits<int>::max();
    return isValidBST(root, low, high);
  }

  bool isValidBST(TreeNode *root, int low, int high) {
    if (root == NULL) return true;

    if (root->val <= low || root->val >= high)
      return false;

    return isValidBST(root->left, low, root->val) &&
           isValidBST(root->right, root->val, high);
  }
};

int main() {
  vector<string> trees = {
    "9 5 3 # # 7 6 # # 8 # # #",
    "9 5 3 # # 7 6 # # 8 # # 12 10 # 11 # # 13 # #",
    "1 2 3 # # # #",
    "3 2 1 # # # #",
    "#",
    "1 # #",
    "3 1 # # 2 # #",
    "2 1 # # 3 # #",
  };
  Solution sol;

  for (auto tree : trees) {
    TreeNode *root = deserialize_tree(tree);
    cout << sol.isValidBST(root) << '\n';
  }
  
  return 0;
}