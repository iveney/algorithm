#include <stack>
#include <iterator>
#include "leetcode.h"

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
      vector<int> result;
      // postorder_recursive(root, result);
      postorder_iterative(root, result);
      return result;
    }

    void postorder_recursive(TreeNode *root, vector<int> &result) {
      if (root == NULL) return;

      postorder_recursive(root->left, result);
      postorder_recursive(root->right, result);
      result.push_back(root->val);
    }

    void postorder_iterative(TreeNode *root, vector<int> &result) {
      if (root == NULL) return;

      stack<TreeNode *> visit;
      visit.push(root);

      while ( !visit.empty() ) {
        TreeNode *node = visit.top();
        visit.pop();

        result.push_back(node->val);
        if (node->left != NULL) {
          visit.push(node->left);
        }

        if (node->right != NULL) {
          visit.push(node->right);
        }
      } // while

      std::reverse(result.begin(), result.end());
    }
};

int main(int argc, char const *argv[])
{
  TreeNode *root = deserialize_tree(string("1 2 # # 3 4 # 5 # #"));
  postorder_cout(root);

  Solution sol;
  auto result = sol.postorderTraversal(root);

  copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
  cout << '\n';

  result.clear();
  sol.postorder_iterative(root, result);
  copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
  cout << '\n';
  return 0;
}