#include "leetcode.h"

class Solution {
public:
  vector<TreeNode *> generateTrees(int n) {
    return generateTrees(1, n);
  }

  vector<TreeNode *> generateTrees(int b, int e) {
    vector<TreeNode *> result;
    if (b>e) result.push_back(NULL);

    for (int i = b; i <= e; ++i) {
      auto left = generateTrees(b, i-1);
      auto right = generateTrees(i+1, e);
      for (auto l : left) {
        for (auto r : right) {
          TreeNode *root = new TreeNode(i);
          root->left = l;
          root->right = r;
          result.push_back(root);
        }
      }
    }

    return result;
  }
};

int main() {
  Solution sol;
  auto result = sol.generateTrees(0);
  for (auto root : result) {
    preorder_cout(root);
  }
  
  return 0;
}