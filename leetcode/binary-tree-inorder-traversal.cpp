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
    vector<int> inorderTraversal(TreeNode *root) {
      vector<int> result;
      // inorder_recursive(root, result);
      inorder_iterative(root, result);
      return result;
    }

    void inorder_recursive(TreeNode *root, vector<int>& result) {
      if (root == NULL) return;
      inorder_recursive(root->left, result);
      result.push_back(root->val);
      inorder_recursive(root->right, result);
    }

    // maintain two stacks L and R.
    // L: whenever pop out an item, push its left child, and push the item to R
    // R: whenever pop out an item, output its value, the push its right child to L
    void inorder_iterative(TreeNode *root, vector<int>& result) {
      stack<TreeNode*> L, R;
      if( root == NULL ) return;

      L.push(root);
      while ( !L.empty() || !R.empty()) {
        TreeNode* p = NULL;

        if (!L.empty()) {
          // process L stack
          p = L.top();
          L.pop();

          R.push(p);
          if (p->left != NULL) {
            L.push(p->left);
          }
        } else {
          // process R stack
          p = R.top();
          R.pop();
          result.push_back(p->val);
          if (p->right != NULL) {
            L.push(p->right);
          }
        }
      }
    }
};

int main(int argc, char const *argv[])
{
  int n = 10;
  TreeNode **nodes = new TreeNode*[n];
  for (int i = 0; i < n; ++i) {
    nodes[i] = new TreeNode(i);
  }
  nodes[0]->left = nodes[1];
  nodes[1]->left = nodes[2];
  nodes[1]->right = nodes[3];
  nodes[2]->left = nodes[4];
  nodes[2]->right = nodes[8];
  nodes[4]->right = nodes[9];
  nodes[3]->left = nodes[5];
  nodes[3]->right = nodes[6];
  nodes[5]->right = nodes[7];

  TreeNode *root = nodes[0];
  Solution sol;
  vector<int> results = sol.inorderTraversal(root);
  for (auto i : results) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}