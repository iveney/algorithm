#include "leetcode.h"

class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    if (head == NULL) return NULL;

    ListNode *p = NULL, *q = NULL, *cur = head->next;
    head->next = NULL;
    while (cur != NULL) {
      // search for insert location
      p = head; q = NULL;
      while (p != NULL && cur->val > p->val) {
        q = p;
        p = p->next;
      }

      ListNode *r = cur;
      cur = cur->next;

      if (q == NULL) {
        head = r;
      } else {
        q->next = r;
      }
      r->next = p;
    }

    return head;
  }
};

int main() {
  Solution sol;
  ListNode nodes[] = {
    10, 9, 8, 7, 6, 5,
    // 6, 5, 9, 4, 2, 10
  };
  int n = sizeof(nodes) / sizeof(ListNode);
  for (int i = 0; i < n-1; ++i)
    nodes[i].next = &nodes[i+1];

  ListNode *head = &nodes[0];
  print_list(head);
  head = sol.insertionSortList(head);
  print_list(head);

  return 0;
}