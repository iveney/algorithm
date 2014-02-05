#include <iostream>
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
      return recur(num, 0, num.size() - 1);
    }

    TreeNode *recur(vector<int> &num, int b, int e) {
      if (b > e)
        return NULL;
      if (b == e)
        return new TreeNode(num[b]);

      int mid = (b + e) / 2;
      TreeNode *root = new TreeNode(num[mid]);
      TreeNode *left = recur(num, b, mid-1);
      TreeNode *right = recur(num, mid+1, e);
      root->left = left;
      root->right = right;
      return root;
    }
};

void inorder(TreeNode* root) {
  if(root == NULL) return;
  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}

int main(int argc, char const *argv[])
{
  int A[] = {1, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = sizeof(A) / sizeof(int);
  vector<int> arr(A, A+n);
  Solution sol;
  TreeNode* root = sol.sortedArrayToBST(arr);
  cout << root->val << endl;
  inorder(root);
  cout << endl;

  return 0;
}