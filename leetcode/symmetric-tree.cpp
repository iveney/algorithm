#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
      if (root == NULL) return true;
      return symmetric(root->left, root->right);
    }
    bool symmetric(TreeNode *left, TreeNode *right) {
      if (left == NULL && right != NULL)
        return false;
      if (left != NULL && right == NULL)
        return false;
      if (left == NULL && right == NULL)
        return true;

      if (left->val != right->val)
        return false;

      bool lsym = symmetric(left->left, right->right);
      bool rsym = symmetric(left->right, right->left);

      return lsym && rsym;
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

  Solution sol;
  TreeNode *root = &nodes[0];
  bool result = sol.isSymmetric(root);
  cout << result << endl;

  nodes[1].left = NULL;
  nodes[1].right = &nodes[3];
  nodes[2].left = NULL;
  nodes[2].right = &nodes[4];
  result = sol.isSymmetric(root);
  cout << result << endl;
  return 0;
}