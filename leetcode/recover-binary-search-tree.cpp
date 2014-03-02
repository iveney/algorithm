// hard problem, need to think again
#include <limits>
#include "leetcode.h"

class Solution {
  int found;
  TreeNode *pred;
  TreeNode *wrong[2];
public:
  void recoverTree(TreeNode *root) {
    found = 0;
    pred = NULL;
    traverse(root);
  }

  // pred: predecessor
  // pred is ready when calling this function
  void traverse(TreeNode *root) {
    if (root == NULL) return;

    // in-order traversal
    traverse(root->left);

    // stop traversing when both of the swapped nodes are found
    if (found == 2) return;

    cout << "Visiting " << root->val << endl;
    if (pred != NULL && pred->val > root->val) {
      // observation: 
      // 1st time when pred > root: pred is the swapped node
      // 2nd time when pred > root: root is the swapped node
      wrong[found] = (found == 0 ? pred : root);
      cout << "Found wrong node " << wrong[found]->val << endl;
      ++found;
      if (found == 2) {
        swap(wrong[0]->val, wrong[1]->val);
        return;
      }
    }

    pred = root; // visit this node, thus this node becomes predecessor

    traverse(root->right);
  }
};

int main() {
  Solution sol;
  string tree = "50 30 20 10 # # # 40 # # 90 70 60 # # 80 # # 100 # #";
  TreeNode *root = deserialize_tree(tree);
  // level_order_cout(root);

  swap(root->left->val, root->right->val);
  // swap(root->val, root->right->left->val);
  // swap(root->val, root->right->val);
  // swap(root->val, root->left->val);
  // swap(root->val, root->right->left->right->val);
  // level_order_cout(root);
  inorder_cout(root);

  sol.recoverTree(root);
  inorder_cout(root);
  // level_order_cout(root);
  
  return 0;
}