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
  Solution sol;
  int a[] = {1,2,3,4,5};
  int n = sizeof(a) / sizeof(int);
  for (int i = 1; i <= n; ++i) {
    ListNode *head = list_from_array(a, n);
    head = sol.removeNthFromEnd(head, i);
    print_list(head);
  }
  return 0;
}