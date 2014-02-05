#ifndef _LEETCODE_H_
#define _LEETCODE_H_

// headers for TreeNode, ListNode, and utility functions

#include <iostream>
#include <functional>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorder(TreeNode *root, function<void(TreeNode*)> func) {
  if (root == NULL)
    return;

  func(root);
  preorder(root->left, func);
  preorder(root->right, func);
}

void inorder(TreeNode *root, function<void(TreeNode*)> func) {
  if (root == NULL)
    return;

  inorder(root->left, func);
  func(root);
  inorder(root->right, func);
}

void postorder(TreeNode *root, function<void(TreeNode*)> func) {
  if (root == NULL)
    return;

  postorder(root->left, func);
  postorder(root->right, func);
  func(root);
}

void preorder_cout(TreeNode *root) {
  preorder(root, [](TreeNode *r) {
    cout << r->val << " ";
  });
  cout << endl;
}

void inorder_cout(TreeNode *root) {
  inorder(root, [](TreeNode *r) {
    cout << r->val << " ";
  });
  cout << endl;
}

void postorder_cout(TreeNode *root) {
  postorder(root, [](TreeNode *r) {
    cout << r->val << " ";
  });
  cout << endl;
}
#endif