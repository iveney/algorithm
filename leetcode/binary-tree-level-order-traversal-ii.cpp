// Given a binary tree, return the bottom-up level order traversal of its nodes'
// values. (ie, from left to right, level by level from leaf to root).

#include "leetcode.h"
#include <stack>
#include <queue>
#include <algorithm>

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
      vector<vector<int> > result;
      if (root == NULL) return result;

      vector<int> level;
      queue<TreeNode *> curr, next;
      queue<TreeNode *> *p_curr = &curr, *p_next = &next;
      p_curr->push(root);

      while (!p_curr->empty()) {
        TreeNode *p = p_curr->front();
        p_curr->pop();

        level.push_back(p->val);
        if (p->left != NULL) {
          p_next->push(p->left);
        }
        if (p->right != NULL) {
          p_next->push(p->right);
        }

        if (p_curr->empty()) {
          result.push_back(level);
          level.clear();

          queue<TreeNode *> *tmp = p_curr;
          p_curr = p_next;
          p_next = tmp;
        }
      } // while

      std::reverse(result.begin(), result.end());
      return result;
    }
};


int main(int argc, char const *argv[])
{
  TreeNode *read = deserialize_tree(string("3 9 # # 20 15 # # 7 # #"));
  Solution sol;
  auto result = sol.levelOrderBottom(read);
  for (auto row : result) {
    for (auto item : row) {
      cout << item << " ";
    }
    cout << '\n';
  }
  return 0;
}

