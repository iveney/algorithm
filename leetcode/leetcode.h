#ifndef _LEETCODE_H_
#define _LEETCODE_H_

// headers for TreeNode, ListNode, and utility functions

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <functional>
#include <vector>
#include <string>
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

void cout_tree_node(TreeNode *node) {
  if (node == NULL) return;
  cout << node->val << " ";
}

void preorder_cout(TreeNode *root) {
  preorder(root, cout_tree_node);
  cout << endl;
}

void inorder_cout(TreeNode *root) {
  inorder(root, cout_tree_node);
  cout << endl;
}

void postorder_cout(TreeNode *root) {
  postorder(root, cout_tree_node);
  cout << endl;
}

void serialize_tree_recursive(FILE* f, TreeNode *root) {
  if (root == NULL) {
    fprintf(f, "# ");
  } else {
    fprintf(f, "%d ", root->val);
    serialize_tree_recursive(f, root->left);
    serialize_tree_recursive(f, root->right);
  }
}

// serialize tree to file using pre-order
void serialize_tree(const char* filename, TreeNode *root) {
  FILE* f = fopen(filename, "w");
  if ( f == NULL ) {
    fprintf(stderr, "Open file %s failed.\n", filename);
    return;
  }

  serialize_tree_recursive(f, root);

  fclose(f);
}

void deserialize_tree_recursive(istream& stream, TreeNode *&node) {
  string token;
  if ( !(stream >> token) )
    return;

  // sentinel
  if (token == "#") {
    node = NULL;
    return;
  }

  int val = stoi(token);
  node = new TreeNode(val);
  deserialize_tree_recursive(stream, node->left);
  deserialize_tree_recursive(stream, node->right);
}

TreeNode *deserialize_tree(const char* filename) {
  ifstream ifs(filename);
  if ( !ifs ) {
    cerr << "Open file " << filename << "failed.\n";
    return NULL;
  }

  TreeNode *root = NULL;
  deserialize_tree_recursive(ifs, root);
  ifs.close();

  return root;
}

// deserialize string from a C++ string
TreeNode *deserialize_tree(const string& serialize_str) {
  istringstream ss(serialize_str);
  TreeNode *root = NULL;
  deserialize_tree_recursive(ss, root);

  return root;
}

#endif