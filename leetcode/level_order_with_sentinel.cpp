#include <queue>
#include "leetcode.h"

void level_order_with_sentinel (TreeNode *root) {
  if(root == NULL) return;
  queue<TreeNode *> myqueue;
  myqueue.push(root);
  myqueue.push(NULL);
  while(!myqueue.empty()) {
    TreeNode *node = myqueue.front();
    myqueue.pop();
    if (node == NULL) {
      cout << '\n';
      if(!myqueue.empty())
        myqueue.push(NULL);
      continue;
    }
    if(node->left)
      myqueue.push(node->left);
    if(node->right)
      myqueue.push(node->right);
    cout << node->val << ' ';
  }
}

int main() {
  string tree = "3 9 # # 20 15 # # 7 # #";
  TreeNode *root = deserialize_tree(tree);
  cout << root << endl;
  level_order_cout(root);
  level_order_with_sentinel(root);
  
  return 0;
}