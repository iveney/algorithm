#include "leetcode.h"

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (head == NULL || k <= 1) return head;

    ListNode *curr_tail = head;
    // search for the curr_tail
    int i = 1;
    while (curr_tail != NULL && i < k) {
      curr_tail = curr_tail->next;
      ++i;
    }

    // not long enough
    if (i < k || curr_tail == NULL) return head;

    ListNode *new_head = curr_tail;
    ListNode *prev_tail = NULL;
    ListNode *curr_head = head;
    ListNode *next_head = curr_tail->next;

    // reverse list until reaches curr_tail
    while (curr_tail != NULL) {
      next_head = curr_tail->next;

      if (prev_tail != NULL) {
        prev_tail->next = curr_tail;
      }

      ListNode *q = curr_head;
      ListNode *p = curr_head->next;
      curr_head->next = next_head;

      // reverse the list, at the same time move the curr_tail
      prev_tail = curr_head;
      curr_tail = next_head;
      curr_head = next_head;
      while (p != next_head) {
        ListNode *next = p->next;
        p->next = q;
        q = p;
        p = next;
        if (curr_tail != NULL)
          curr_tail = curr_tail->next;
      }
    } // while
    return new_head;
  }
};

int main() {
  Solution sol;
  vector<vector<ListNode> > nodes {
    {1, 2, 3}, // - list shorter than k
    {1, 2},    // - list shorter than k
    {},        // - empty list
    {1, 2, 3, 4, 5, 6}, // - number of nodes are multiples of k
    {1, 2, 3, 4, 5, 6}, // - k = 1
    {1, 2, 3, 4, 5, 6}, // - k = 0
    {1, 2, 3, 4, 5},    // - normal
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},    // - normal
  };

  vector<int> K {
    4,
    4,
    0,
    2,
    0,
    1,
    2,
    3,
  };

  for (int i = 0; i < nodes.size(); ++i)
  {
    auto &nodelist = nodes[i];
    int n = nodelist.size();
    ListNode *head = (n > 0 ? &nodelist[0] : NULL);
    for (int j = 0; j < n - 1; ++j) {
      nodelist[j].next = &nodelist[j+1];
    }

    printf("[%d] Original: ", i);
    print_list(head);
    printf("[%d] Modified: ", i);
    head = sol.reverseKGroup(head, K[i]);
    print_list(head);
  }

  return 0;
}