#include <list>
#include "../leetcode/leetcode.h"

list<list<TreeNode *> > level_traversal(TreeNode *root) {
  list<list<TreeNode *> > result;
  if (root == NULL) return result;
  result.push_back({root});
  while (true) {
    auto &prev_list = result.back();
    list<TreeNode *> mylist;
    for (TreeNode *node : prev_list) {
      if (node->left != NULL)
        mylist.push_back(node->left);
      if (node->right != NULL)
        mylist.push_back(node->right);
    }
    if (!mylist.empty())
      result.push_back(mylist);
    else
      break;
  }
  return result;
}


int main(int argc, char const *argv[]) {
  string tree = "50 30 20 10 # # # 40 # # 90 70 60 # # 80 # # 100 # #";
  TreeNode *root = deserialize_tree(tree);

  auto result = level_traversal(root);
  for (auto level : result) {
    for (auto node : level) {
      cout << node->val << ' ';
    }
    cout << '\n';
  }
  
  return 0;
}