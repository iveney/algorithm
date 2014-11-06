// http://leetcode.com/2011/04/construct-binary-tree-from-inorder-and-preorder-postorder-traversal.html
// idea is to partition into two subarrays and recursively build tree
// given inorder:
// [ .. L .. ] [root] [ .. R .. ]
// and preorder
// [root] [ .. L .. ] [ .. R .. ]
#include "leetcode.h"

class SolutionV2 {
public:
  unordered_map<int, int> inorder_map;
  TreeNode *buildTreeRecursive(vector<int> &preorder, vector<int> &inorder,
    int pb, int pe, int ib, int ie) {
    if (pb == pe) return nullptr;

    int rootval = preorder[pb];
    int pivot = inorder_map[rootval];
    TreeNode *root = new TreeNode(rootval);
    int lsize = pivot - ib;
    root->left  = buildTreeRecursive(preorder, inorder, pb + 1, pb + 1 + lsize, ib, pivot);
    root->right = buildTreeRecursive(preorder, inorder, pb + 1 + lsize, pe, pivot+1, ie);
    return root;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); ++i) {
      inorder_map[inorder[i]] = i;
    }
    return buildTreeRecursive(preorder, inorder, 0, preorder.size(), 0, inorder.size());
  }
};

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size();
    int p = 0;
    return buildTree(preorder, p, inorder, 0, n-1);
  }

  TreeNode *buildTree(vector<int> &preorder, int &p,
                      vector<int> &inorder, int b, int e) {
    if (b > e) return NULL;

    int val = preorder[p++];
    TreeNode *root = new TreeNode(val); 

    int i;
    for (i=b; i<=e; i++) {
      if (inorder[i] == val)
        break;
    }

    root->left = buildTree(preorder, p, inorder, b, i-1);
    root->right = buildTree(preorder, p, inorder, i+1, e);
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
  vector<vector<int> > preorder = {
    {1,2,3,4,5},
    {1,2,3,4,5,6,7,9,8},
    {1},
    {},
  };
  vector<vector<int> > inorder = {
    {2,1,4,3,5},
    {3,2,5,4,1,7,9,6,8},
    {1},
    {},
  };

  Solution sol;
  for(int i=0; i<trees.size(); ++i) {
    TreeNode *de = deserialize_tree(trees[i]);
    preorder_cout(de);
    TreeNode *root = sol.buildTree(preorder[i], inorder[i]);
    preorder_cout(root);
    cout << '\n';
  }
  
  return 0;
}