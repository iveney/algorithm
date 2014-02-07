#include "leetcode.h"

int main(int argc, char const *argv[])
{
  
  TreeNode nodes[] = {
    TreeNode(1), // 0
    TreeNode(2), TreeNode(2),  // 1, 2
    TreeNode(3), TreeNode(3),  // 3, 4
    TreeNode(4), TreeNode(4),  // 5, 6
  };
  nodes[0].left = &nodes[1];
  nodes[0].right = &nodes[2];
  nodes[1].left = &nodes[3];
  nodes[1].right = &nodes[5];
  nodes[2].left = &nodes[6];
  nodes[2].right = &nodes[4];

  TreeNode *root = &nodes[0];
  preorder_cout(root);

  serialize_tree("tmp.txt", root);
  TreeNode *read = deserialize_tree("tmp.txt");
  preorder_cout(read);

  read = deserialize_tree(string("1 # 2 3"));
  preorder_cout(read);
  return 0;
}