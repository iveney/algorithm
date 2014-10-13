#include "leetcode.h"

// Implement iteratively
// idea is to maintain two queues for current level, check if they are reversely the same
// also fill the next level queues when comparing.
class SolutionIterative {
public:
  bool isSymmetric(TreeNode *root) {
    if (root == NULL) return true;

    curL = &L[0];
    curR = &R[0];
    nxtL = &L[1];
    nxtR = &R[1];
    curL->push_back(root->left);
    curR->push_back(root->right);
    while (!curL->empty() && !curR->empty()) {
      TreeNode *l = curL->front();
      curL->pop_front();
      TreeNode *r = curR->back();
      curR->pop_back();

      if (l == NULL && r == NULL) {
        // fine
      } else if (l == NULL || r == NULL) {
        // one of them is not NULL
        return false;
      } else if (l->val != r->val) {
        return false;
      } else {
        nxtL->push_back(l->left);
        nxtL->push_back(l->right);
        nxtR->push_front(r->right);
        nxtR->push_front(r->left);
      }

      if (curL->empty() && curR->empty()) {
        // finish current level, swap pointers for the next level  
        swap(curL, nxtL);
        swap(curR, nxtR);
      } else if (curL->empty() || curR->empty()) {
        // uneven number at the current levels
        return false;
      }
    } // while
    return true;
  }

  list<TreeNode *> L[2], R[2], *curL, *curR, *nxtL, *nxtR; // rotate them
};

// more compact
class SolutionV2 {
public:
    bool isMirror(TreeNode *l, TreeNode *r) {
        if (l == NULL && r == NULL) return true;
        if (l == NULL || r == NULL) return false;
        if (l->val != r->val) return false;
        return isMirror(l->left, r->right) && isMirror(l->right, r->left);
    }
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        
        return isMirror(root->left, root->right);
    }
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
  vector<string> trees = {
    "1 2 3 # # 4 # # 2 4 # # 3 # #",
    "1 2 # 3 # # 2 # 3 # #",
    "2 3 4 # # 5 8 # # 9 # # 3 5 9 # # 8 # # 4 # #",
  };
  for (auto tree : trees) {
    TreeNode *root = deserialize_tree(tree);
    Solution sol;
    SolutionIterative soli;
    cout << sol.isSymmetric(root) << '\n';
    cout << soli.isSymmetric(root) << '\n';
  }
  // level_order_cout(root);

  return 0;
}