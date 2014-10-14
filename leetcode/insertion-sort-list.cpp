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
  // vector<int> l = {10, 10, 10, 9, 8, 7};
  // vector<int> l = {10};
  vector<int> l = {3, 9, 2, 1, 0, 10, 7};
  ListNode *head = list_from_array(l);
  print_list(head);
  ListNode *newhead = sol.insertionSortList(head);
  print_list(newhead);

  return 0;
}