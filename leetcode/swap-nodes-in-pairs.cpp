#include "leetcode.h"

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

class SolutionRecursive {
public:
  ListNode *swapPairs(ListNode *head) {
    // try recursive
    if (head == NULL) return NULL;

    ListNode *p = head, *q = head->next;
    if (q == NULL) {
      return p;
    }
    ListNode *r = swapPairs(q->next);
    p->next = r;
    q->next = p;

    return q;
  }
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
      ListNode *p = head;
      ListNode *prev = NULL;
      while (p!=NULL) {
        if (p->next == NULL)
          break;

        ListNode *q = p->next;
        if (prev != NULL) {
          prev->next = q;
        } else {
          // first swap
          head = q;
        }
        p->next = q->next;
        q->next = p;
        prev = p;
        p = p->next;
      }
      return head;
    }
};

int main(int argc, char const *argv[])
{
  vector<vector<int> > lists {
    {1,2,3,4},
    {1,2,3},
    {1,2},
    {1},
    {},
  };
  Solution sol;
  for (auto &l : lists) {
    ListNode *head = list_from_array(l);
    print_list(head);
    ListNode *newhead = sol.swapPairs(head);
    print_list(newhead);
  }
  return 0;
}