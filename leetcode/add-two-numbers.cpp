#include "leetcode.h"

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (l1 == NULL && l2 == NULL) return new ListNode(0);

    ListNode *head = NULL;
    ListNode *tail = NULL;
    int carry = 0;
    while (l1 != NULL || l2 != NULL) {
      int val = carry;
      if (l1 != NULL)
        val += l1->val;
      if (l2 != NULL)
        val += l2->val;

      carry = (val > 9);
      val %= 10;
      ListNode *sum = new ListNode(val);
      if (tail) {
        tail->next = sum;
        tail = tail->next;
      } else {
        head = tail = sum;
      }
      l1 = (l1 == NULL? NULL : l1->next);
      l2 = (l2 == NULL? NULL : l2->next);
    }

    // check if need to carry one more
    if (carry) {
      tail->next = new ListNode(1);
    }

    return head;
  }
};

ListNode *chain_list(vector<ListNode> &list) {
  if (list.size() == 0) return NULL;
  for (int i = 0; i < list.size() - 1; ++i)
  {
    list[i].next = &list[i+1];
  }
  return &list[0];
}

int main() {
  vector<vector<ListNode> > l1 {
    {2, 4, 3},
    {9, 9, 9},
    {1, 1, 9, 9, 9},
    {},
    {},
  };
  vector<vector<ListNode> > l2 {
    {5, 6, 4},
    {1},
    {0, 9, },
    {0, 0, 2},
    {},
  };

  Solution sol;
  for (int i = 0; i < l1.size(); ++i) {
    ListNode *p1 = chain_list(l1[i]);
    ListNode *p2 = chain_list(l2[i]);
    ListNode *head = sol.addTwoNumbers(p1, p2);
    print_list(head);
  }
  
  return 0;
}