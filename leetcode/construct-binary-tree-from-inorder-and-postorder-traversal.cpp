#include "leetcode.h"

class Solution {
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int n = inorder.size();
    int p = n-1;
    return buildTree(inorder, 0, n-1, postorder, p);
  }

  TreeNode *buildTree(vector<int> &inorder, int b, int e,
                 vector<int> &postorder, int &p) {
    if (b > e || p < 0) return NULL;

    int val = postorder[p--];
    TreeNode *root = new TreeNode(val);
    int i;
    for (i = b; i <= e; ++i) {
      if (inorder[i] == val)
        break;
    }

    root->right = buildTree(inorder, i+1, e, postorder, p);
    root->left = buildTree(inorder, b, i-1, postorder, p);
    return root;
  }
};

int main() {
  vector<string> trees = {
    "1 2 # # 3 4 # # 5 # #",
    "1 2 3 # # 4 5 # # # 6 7 # 9 # # 8 # #",
    "1 # #",
    "#",
  };
  vector<vector<int> > inorder = {
    {2,1,4,3,5},
    {3,2,5,4,1,7,9,6,8},
    {1},
    {},
  };
  vector<vector<int> > postorder = {
    {2,4,5,3,1},
    {3,5,4,2,9,7,8,6,1},
    {1},
    {},
  };

  Solution sol;
  for(int i=0; i<trees.size(); ++i) {
    TreeNode *de = deserialize_tree(trees[i]);
    preorder_cout(de);
    TreeNode *root = sol.buildTree(inorder[i], postorder[i]);
    preorder_cout(root);
    cout << '\n';
  }
  
  return 0;
}