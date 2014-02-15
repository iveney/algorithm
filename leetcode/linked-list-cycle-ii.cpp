// classical problem. Think & practice again!!

#include "leetcode.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      if ( head == NULL ) return NULL;

      ListNode *p, *q;
      p = q = head;

      do {
        p = p->next;
        q = q->next;
        if (q != NULL)
          q = q->next;

        if ( p == q )
          break;
      }
      while (p != NULL && q != NULL);

      // no cycle
      if (p == NULL || q == NULL)
        return NULL;

      q = head; // reset
      while (p != q) {
        q = q->next;
        p = p->next;
      }

      return p;
    }
};

int main(int argc, char const *argv[])
{
  const int N = 10;
  ListNode nodes[N];
  for (int i = 0; i < N - 1; ++i) {
    nodes[i].val = i;
    nodes[i].next = &nodes[i+1];
  }

  // make a cycle
  nodes[9].val = 9;
  nodes[9].next = &nodes[9];

  Solution sol;
  ListNode *head = &nodes[0];
  ListNode *node = sol.detectCycle(head);
  if (node!=NULL)
    cout << node->val << endl;
  return 0;
}