#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
      vector<int> result;
      // preorder_recursive(root, result);
      preorder_iterative(root, result);
      return result;
    }

    void preorder_recursive(TreeNode *root, vector<int>& result) {
      if (root == NULL) return;
      result.push_back(root->val);
      preorder_recursive(root->left, result);
      preorder_recursive(root->right, result);
    }

    void preorder_iterative(TreeNode *root, vector<int>& result) {
      stack<TreeNode*> st;
      st.push(root);
      while( !st.empty() ) {
        TreeNode* p = st.top();
        st.pop();
        if (p == NULL) continue;
        
        result.push_back(p->val);
        if (p->left != NULL) {
          st.push(p->left);
        }
        if (p->right != NULL) {
          st.push(p->right);
        }
      }
    }
};

int main(int argc, char const *argv[])
{
  TreeNode *root = new TreeNode(1);
  TreeNode *a = new TreeNode(2), *b = new TreeNode(3);
  root->right = a;
  a->left = b;
  Solution sol;
  vector<int> results = sol.preorderTraversal(root);
  for (auto i : results) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}