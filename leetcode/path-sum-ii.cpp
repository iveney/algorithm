#include "leetcode.h"

class Solution {
  vector<vector<int> > result;
public:
  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<int> prefix;
    pathSum(root, sum, prefix);
    return result;
  }

  void pathSum(TreeNode *root, int sum, vector<int> &prefix) {
    if (root == NULL) return;

    prefix.push_back(root->val);
    if (root->left == NULL && root->right == NULL) {
      // leaf node
      if (sum == root->val) {
        result.push_back(prefix);
      }
    } else {
      pathSum(root->left, sum - root->val, prefix);
      pathSum(root->right, sum - root->val, prefix);
    }
    prefix.pop_back();
  }
};

int main() {
  Solution sol;
  string serialized_tree("5 4 11 7 # # 2 # # # 8 13 # # 4 5 # # 1 4 # # #");
  TreeNode *root = deserialize_tree(serialized_tree);
  preorder_cout(root);
  int sum = 22;
  // auto result = sol.pathSum(root, sum);
  // auto result = sol.pathSum(NULL, 0);
  // auto result = sol.pathSum(root->right->left, 13);
  auto result = sol.pathSum(root->right->right, 9);
  for (auto row: result) {
    copy(row.begin(), row.end(), 
      ostream_iterator<decltype(row)::value_type>(cout, " "));
    cout << '\n';
  }
  return 0;
}