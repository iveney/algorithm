#include <iostream>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
    int maxDepth(TreeNode *root) {
      if (root == NULL) return 0;
      int left_height = maxDepth(root->left);
      int right_height = maxDepth(root->right);
      int depth = (left_height > right_height) ? left_height : right_height;
      return depth + 1;
    }
};

int main() {
  TreeNode* root = new TreeNode(1);
  TreeNode* a = new TreeNode(2);
  TreeNode* b = new TreeNode(3);
  root->left = a; root->right = b;

  TreeNode* c = new TreeNode(4);
  TreeNode* d = new TreeNode(5);
  TreeNode* e = new TreeNode(6);

  a->left = c;
  c->right = d;
  b->right = e;

  Solution sol;
  cout << sol.maxDepth(root) << endl;
  cout << sol.maxDepth(a) << endl;
  cout << sol.maxDepth(b) << endl;
  cout << sol.maxDepth(e) << endl;
  return 0;
}