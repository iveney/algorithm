#include <list>
#include "leetcode.h"
#include "array2D.hpp"

class Solution {
public:
  vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> > result;
    if (root == NULL) return result;

    list<TreeNode*> curr, next;
    list<TreeNode*> *p_curr = &curr, *p_next = &next;
    p_curr->push_back(root);

    int ltor = 1;
    vector<int> buffer;
    while (!p_curr->empty()) {
      TreeNode *node = p_curr->front();
      p_curr->pop_front();

      buffer.push_back(node->val);

      if (ltor) {
        if (node->left)
          p_next->push_front(node->left);
        if (node->right)
          p_next->push_front(node->right);
      } else {
        if (node->right)
          p_next->push_front(node->right);
        if (node->left)
          p_next->push_front(node->left);
      }

      if (p_curr->empty()) {
        swap(p_curr, p_next);
        ltor = 1 - ltor;
        result.push_back(buffer);
        buffer.clear();
      }
    } // while

    return result;
  }
};

int main() {
  Solution sol;
  string tree = "3 9 1 # 4 # # 2 8 # # # 20 15 # # 7 # #";
  TreeNode *root = deserialize_tree(tree);
  auto result = sol.zigzagLevelOrder(root);
  print_2D<int>(result);
  
  return 0;
}