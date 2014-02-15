// need to practice this again, WA 3 times
// can probably just do a level order traversal
#include "leetcode.h"

class Solution {
public:
  TreeLinkNode *leftmost(TreeLinkNode *node) {
    TreeLinkNode *p = node;
    while (p != NULL && p->left == NULL && p->right == NULL) {
      // cout << "p : " << p->val << endl;
      p = p->next;
    }
    return p;
  }

  void print_level(TreeLinkNode *root) {
    TreeLinkNode *l = root, *p = NULL;

    while (l != NULL) {
      p = l;
      while (p != NULL) {
        cout << p->val << ' ';
        p = p->next;
      }
      cout << "# ";

      l = leftmost(l);
      if (l == NULL)
        break;
      if (l->left != NULL)
        l = l->left;
      else
        l = l->right;
    }
    cout << '\n';
  }

  void connect(TreeLinkNode *root) {
    if (root == NULL) return;
    connect(root->left); 
    connect(root->right);

    // now that left and right are already connected
    TreeLinkNode *l = root->left;
    TreeLinkNode *r = root->right;
    TreeLinkNode *lr = l;
    while (l != NULL && r != NULL) {
      l = leftmost(l);
      lr->next = r;

      if (l == NULL)
        break;
      if (l->left != NULL)
        l = l->left;
      else
        l = l->right;

      lr = l;
      while (lr != NULL && lr->next != NULL) {
        lr = lr->next;
      }

      r = leftmost(r);
      if (r == NULL)
        break;
      if (r->left != NULL)
        r = r->left;
      else
        r = r->right;
    } // while
  }
};

int main() {
  string tree("1 2 4 7 # # # 5 # # 3 # 6 # 8 # #");
  // string tree("2 1 0 2 # # # 7 1 # # 0 7 # # # 3 9 # # 1 8 # # 8 # #");
  // string tree("7 -10 -4 # # 3 # -1 # # 2 -8 11 # # # #");
  TreeNode *t = deserialize_tree(tree);
  TreeLinkNode *root = fromTreeNode(t);
  // printTreeLinkNode(root);
  // cout << '\n';
  Solution sol;
  sol.connect(root);
  // printTreeLinkNode(root);

  // level_order_cout(t);
  sol.print_level(root);

  return 0;
}