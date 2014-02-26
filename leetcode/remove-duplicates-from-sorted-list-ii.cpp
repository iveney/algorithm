#include "leetcode.h"

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == NULL) return NULL;
    ListNode *r = NULL, *q = head, *p = head->next;

    while (p != NULL) {
      if (p->val != q->val) {
        r = q;
        q = p;
        p = p->next;
      } else {
        // found duplicate, search until different
        while (p != NULL && p->val == q->val) {
          p = p->next;
        }

        if (r != NULL) {
          r->next = p;
          q = r;
          r = NULL;
        } else {
          // duplicate happens at head
          head = p;
          if ( p == NULL )
            break;
          q = p;
          p = p->next;
        }
      }
    } // while

    return head;
  }
};

int main() {
  Solution sol;
  vector<vector<int> > arr = {
    {1,2,3,3,4,4,5},
    {1,1,1,2,3},
    {1,2,3,3,4,4,4},
    {1,1,2,2,},
    {1,1,},
    {1},
    {3,3,3,3,3,3,4,4,4,5,5,5,5,5,6,7,7,}
  };

  for (auto A : arr) {
    ListNode *head = list_from_array(A.data(), A.size());
    head = sol.deleteDuplicates(head);
    print_list(head);
  }
  return 0;
}