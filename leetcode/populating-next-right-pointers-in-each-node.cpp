// http://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/
#include <iostream>
using namespace std;

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
      if (root == NULL) return;
      connect(root->left);
      connect(root->right);
      TreeLinkNode* p = root->left;
      TreeLinkNode* q = root->right;
      while (p != NULL) {
        p->next = q;
        p = p->right;
        q = q->left;
      }
    }
};

void print_val(TreeLinkNode *node) {
  if (node == NULL)
    cout << "0";
  else
    cout << node->val;
}


void print_tree(TreeLinkNode *root) {
  if (root == NULL) return;
  cout << root->val << ":";
  cout << " l = ";
  print_val(root->left);
  cout << " r = ";
  print_val(root->right);
  cout << " n = ";
  print_val(root->next);
  cout << endl;
  print_tree(root->left);
  print_tree(root->right);
}

int main(int argc, char const *argv[])
{
  TreeLinkNode *nodes[9];
  for (int i = 1; i < 8; ++i) {
    nodes[i] = new TreeLinkNode(i);
  }
  nodes[1]->left = nodes[2]; nodes[1]->right = nodes[3];
  nodes[2]->left = nodes[4]; nodes[2]->right = nodes[5];
  nodes[3]->left = nodes[6]; nodes[3]->right = nodes[7];
  print_tree(nodes[1]);
  Solution sol;

  cout << "\n\n";
  sol.connect(nodes[1]);
  print_tree(nodes[1]);

  return 0;
}