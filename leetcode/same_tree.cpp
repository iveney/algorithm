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
    bool isSameTree(TreeNode *p, TreeNode *q) {
      if (p == NULL && q == NULL) 
        return true;
      else if (p == NULL || q == NULL)
        return false;

      return p->val == q->val && 
             isSameTree(p->left, q->left) &&
             isSameTree(p->right, q->right);
    }
};

int main() {
  TreeNode* root = new TreeNode(1);
  TreeNode* a = new TreeNode(1);
  TreeNode* b = new TreeNode(1);
  root->left = a; root->right = b;

  TreeNode* c = new TreeNode(1);
  TreeNode* d = new TreeNode(1);
  TreeNode* e = new TreeNode(1);

  a->left = c;
  c->right = d;
  b->right = e;

  Solution sol;
  cout << sol.isSameTree(root, root) << endl;
  cout << sol.isSameTree(NULL, root) << endl;
  cout << sol.isSameTree(a, b) << endl;
  cout << sol.isSameTree(c, b) << endl;
  return 0;
}
