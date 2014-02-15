#include "leetcode.h"

class Solution {
public:
    int minDepth(TreeNode *root) {
      if (root == NULL) return 0;

      int ldepth = minDepth(root->left);
      int rdepth = minDepth(root->right);

      if (root->left == NULL) {
        return 1 + rdepth;
      }

      if (root->right == NULL) {
        return 1 + ldepth;
      }

      return 1 + min(ldepth, rdepth);
    }

};

int main(int argc, char const *argv[])
{
  string serialized_tree("3 9 # # 20 15 # 8 4 # # # 7 # #");
  TreeNode *root = deserialize_tree(serialized_tree);
  Solution sol;
  cout << sol.minDepth(root) << endl;
  cout << sol.minDepth(NULL) << endl;
  cout << sol.minDepth(root->left) << endl;
  cout << sol.minDepth(root->right) << endl;
  cout << sol.minDepth(root->right->left) << endl;

  return 0;
}