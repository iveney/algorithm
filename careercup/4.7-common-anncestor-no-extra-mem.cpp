#include "../leetcode/leetcode.h"

enum Status{NOTFOUND, A, B, BOTH};
struct Result {
  Result(Status s, TreeNode *node) : status(s), LCA(node) {}
  Status status;
  TreeNode *LCA;
};

Result LCA(TreeNode *root, TreeNode *a, TreeNode *b) {
  if (root == NULL)
    return Result(NOTFOUND, NULL);

  if (root == a && root == b) {
    return Result(BOTH, root);
  }

  Result l = LCA(root->left, a, b);
  if (l.LCA != NULL)
  // already found LCA
    return l;

  Result r = LCA(root->right, a, b);
  if (r.LCA != NULL)
  // already found LCA
    return r;

  if (l.status != NOTFOUND && r.status != NOTFOUND)
    // a and b in different subtree: this is the LCA
    return Result(BOTH, root);
  else if (root == a || root == b) {
    // root is a (or b), and b (or a) is in one subtree
    if (l.status != NOTFOUND || r.status != NOTFOUND)
      return Result(BOTH, root);

    return Result (root == a ? A : B, NULL);
  } else {
    if (l.status != NOTFOUND)
      return l;
    if (r.status != NOTFOUND)
      return r;
  }

  return Result(NOTFOUND, NULL);
}

int main() {
  TreeNode *root = deserialize_tree(string("3 9 # # 20 15 # # 7 # #"));
  // level_order_cout(root);
  Result result =  LCA(root, root->right->right, root->right->left);
  if (result.LCA != NULL)
    cout << result.LCA->val << '\n';
  
  return 0;
}