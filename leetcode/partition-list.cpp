#include "leetcode.h"

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    if (head == NULL) return NULL;

    // search for the 1st node with val >= x
    ListNode *p = head, *q = NULL;
    while (p != NULL && p->val < x) {
      q = p;
      p = p->next;
    }

    // cannot find such a node: all values are < x
    if (p == NULL) return head;

    ListNode *big = q;
    while (p != NULL) {
      if (p->val < x) {
        ListNode *pnext = p->next;
        if (q != NULL)
          q->next = p->next;
        if (big != NULL) {
          p->next = big->next;
          big->next = p;
        } else {
          p->next = head;
          head = p;
        }
        big = p;
        p = pnext;
      } else {
        q = p;
        p = p->next;
      }
    } // while
    return head;
  }
};

int main() {
  int x = 3;
  vector<vector<int> > A = {
    {3, 2, 1, 2}, // --> 2 1 2 3
    {1, 4, 3, 2, 5, 2},
    {2, 2, 2},
    {2, 2, 4},
    {3, 4, 2},
    {2},
    {3},
    {4},
    {},
  };
  Solution sol;
  for (auto arr: A) {
    ListNode * head = list_from_array(arr.data(), arr.size());
    print_list(head);
    head = sol.partition(head, x);
    print_list(head);
    printf("\n");
  }
  
  return 0;
}