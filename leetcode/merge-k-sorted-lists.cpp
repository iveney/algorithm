// another idea is to use mergesort, which merges two lists together
#include "leetcode.h"

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *head = NULL, *tail = NULL;

    while (true) {
      // search for the next min
      int min_id = -1;
      for (int i = 0; i < lists.size(); ++i) {
        if (lists[i] != NULL && 
            (min_id == -1 || lists[i]->val < lists[min_id]->val) ) {
          min_id = i;
        }
      } //for

      // all lists are done
      if (min_id == -1) break;

      if (head == NULL) {
        head = tail = lists[min_id];
      } else {
        tail->next = lists[min_id];
        tail = lists[min_id];
      }
      lists[min_id] = lists[min_id]->next;
    } // while
    return head;
  }
};

int main() {
  Solution sol;
  vector<ListNode> nodes {
    3, 4, 4, 7, 0, 7, 7, 8, 0, 9
  };
  vector<ListNode *> lists(nodes.size()/2);
  for (int i = 0; i < nodes.size()/2; ++i) {
    lists[i] = &nodes[2*i];
    lists[i]->next = &nodes[2*i+1];
    print_list(lists[i]);
  }

  ListNode *head = sol.mergeKLists(lists);
  print_list(head);

  return 0;
}