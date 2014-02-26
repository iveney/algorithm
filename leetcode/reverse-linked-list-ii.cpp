#include "leetcode.h"

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (head == NULL) return NULL;

    ListNode *old_tail = NULL, *rhead = head;

    // search for reverse start point
    int i = 1;
    while (i < m) {
      ++i;
      old_tail = rhead;
      rhead = rhead->next;
    }

    // start to reverse
    ListNode *q = NULL, *p = rhead, *r = NULL;
    while (i <= n) {
      ++i;
      r = q;
      q = p;
      p = p->next;
      q->next = r;
    }

    // q points to the tail of reverse list
    if (old_tail != NULL) {
      old_tail->next = q;
    } else {
      // m = 1
      head = q;
    }

    rhead->next = p;

    return head;
  }

};

int main() {
  ListNode nodes[5];
  int i;
  for (i = 0; i < 4; ++i)
  {
    nodes[i].val = i+1;
    nodes[i].next = &nodes[i+1];
  }
  nodes[i].val = i+1;
  Solution sol;
  ListNode *head = &nodes[0];
  int m = 4, n = 5;
  print_list(head);
  head = sol.reverseBetween(head, m, n);
  print_list(head);
  
  return 0;
}