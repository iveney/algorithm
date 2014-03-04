#include "leetcode.h"

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {

      // get the length of list
      int len = 0;
      ListNode *p = head, *tail = NULL;
      while (p != NULL) {
        ++len;
        tail = p;
        p = p->next;
      }

      // handle trivial cases
      if (len <= 1 || k % len == 0) return head;

      int idx = len - (k % len);
      ListNode *newhead = head, *newtail = NULL;
      while (idx > 0) {
        newtail = newhead;
        newhead = newhead->next;
        --idx;
      }

      tail->next = head;
      newtail->next = NULL;
      return newhead;
    }
};

int main() {
  Solution sol;
  vector<ListNode> nodes {
    1, 2, 3, 4, 5,
  };

  int n = 10;
  for (int i = 0; i < n; ++i) {
    vector<ListNode> cp(nodes);
    for (int j = 0; j < cp.size() - 1; ++j) {
      cp[j].next = &cp[j+1];
    }
    printf("k=%d\n", i);
    ListNode *head = &cp[0];
    print_list(head);
    head = sol.rotateRight(head, i);
    print_list(head);
  }
  
  return 0;
}