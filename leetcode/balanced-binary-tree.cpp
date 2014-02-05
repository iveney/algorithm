#include "leetcode.h"

class Solution {
public:
    bool isBalanced(TreeNode *root) {
      int height;
      return isBalanced(root, height);
    }
    bool isBalanced(TreeNode *root, int &height) {
      if (root == NULL) {
        height = 0;
        return true;
      }

      int lh = 0, rh = 0;
      bool l_bal = isBalanced(root->left, lh);
      bool r_bal = isBalanced(root->right, rh);
      height = max(lh, rh) + 1;
      return (l_bal && r_bal && abs(lh - rh) <= 1);
    }
};

int main(int argc, char const *argv[])
{
  TreeNode nodes[] = {
    TreeNode(1), // 0
    TreeNode(2), TreeNode(2),  // 1, 2
    TreeNode(3), TreeNode(3),  // 3, 4
    TreeNode(4), TreeNode(4),  // 5, 6
  };
  nodes[0].left = &nodes[1];
  nodes[0].right = &nodes[2];
  nodes[1].left = &nodes[3];
  nodes[1].right = &nodes[5];
  nodes[2].left = &nodes[6];
  nodes[2].right = &nodes[4];

  TreeNode *root = &nodes[0];
  Solution sol;
  cout << sol.isBalanced(root) << endl;

  return 0;
}