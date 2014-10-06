#include "leetcode.h"

int main() {
  string str;
  getline(cin, str);
  TreeNode *root = deserialize_tree(str);
  dump_tree_graphviz("tree", root);
  
  return 0;
}  