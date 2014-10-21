// Another solution is:
// 1. find the middle point of the list (two pointers, one go 2x, one go 1x)
// 2. reverse the last half of the list
// 3. merge two list
// Time complexity will still be O(n), two passes, code is more complicated though.

#include <stack>
#include "leetcode.h"

class Solution {
public:
  void reorderList(ListNode *head) {
    if (head == NULL) return;

    stack<ListNode *> st;
    ListNode *p = head;
    while (p != NULL) {
      st.push(p);
      p = p->next;
    }

    int n = st.size();
    p = head;
    for (int i = 0; i < n/2; ++i) {
      ListNode *q = st.top();
      st.pop();
      q->next = p->next;
      p->next = q;
      p = q->next;
    }

    // fix the loop
    p->next = NULL;
  }
};

int main() {
  vector<vector<int> > arr{
    {1, 2, 3, 4, 5,},
    {1, 2, 3, 4, 5, 6},
    {1},
    {1, 2},
    {}
  };
  Solution sol;
  for (auto v : arr) {
    ListNode *head = list_from_array(v.data(), v.size());
    print_list(head);
    sol.reorderList(head);
    print_list(head);
  }
  
  return 0;
}