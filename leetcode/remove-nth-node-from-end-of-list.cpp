// brain-teaser, interesting question. Practice (think) again!

#include "leetcode.h"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
      if (head == NULL) return NULL;

      // assume n is valid
      ListNode *p, *q, *r;
      p = q = head;
      r = NULL;

      for (int i = 0; i < n - 1; ++i) {
        p = p->next;
      }

      while (p->next != NULL) {
        p = p->next;
        r = q;
        q = q->next;
      }

      if ( r == NULL ) {
        head = q->next;
      } else {
        r->next = q->next;
      }
      return head;
    }
};

int main(int argc, char const *argv[])
{
  const int n = 5;
  ListNode nodes[n];
  for (int i = 0; i < n - 1; ++i) {
    nodes[i].val = i+1;
    nodes[i].next = &nodes[i+1];
  }
  nodes[n-1].val = n;
  ListNode *head = &nodes[0];
  print_list(head);

  Solution sol;
  ListNode *nhead = sol.removeNthFromEnd(head, 5);
  print_list(nhead);

  nhead = &nodes[n-1];
  print_list(nhead);
  nhead = sol.removeNthFromEnd(nhead, 1);
  print_list(nhead);
  return 0;
}