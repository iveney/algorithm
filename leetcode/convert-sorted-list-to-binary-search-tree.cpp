// good question, didn't come out the solution at the first hand
// need to practice again
#include "leetcode.h"

class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    if (head == NULL) return NULL;

    ListNode *p = head;
    int n = 0;
    while (p != NULL) {
      ++n;
      p = p->next;
    }

    p = head;
    return sortedListToBST(p, 0, n-1);
  }

  TreeNode *sortedListToBST(ListNode *&head, int b, int e) {
    if (b > e) return NULL;

    int mid = (b+e)/2;
    TreeNode *left = sortedListToBST(head, b, mid-1);
    TreeNode *node = new TreeNode(head->val);
    node->left = left;
    head = head->next;
    TreeNode *right = sortedListToBST(head, mid+1, e);
    node->right = right;

    return node;
  }
};

int main() {
  const int n=10;
  ListNode a[n];
  for (int i = 0; i < n; ++i) {
    a[i].val = i;
    if (i < n-1)
      a[i].next = &a[i+1];
  }

  Solution sol;
  TreeNode *root = sol.sortedListToBST(&a[0]);
  level_order_cout(root);
  
  return 0;
}