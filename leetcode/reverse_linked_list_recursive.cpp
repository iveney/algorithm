#include "leetcode.h"

void reverse_print_list(ListNode *head) {
  if (head == NULL) return;

  reverse_print_list(head->next);
  cout << head->val << ' ';
}

int main() {
  ListNode nodes[5];
  int i;
  for (i = 0; i < 4; ++i)
  {
    nodes[i].val = i+1;
    nodes[i].next = &nodes[i+1];
  }
  nodes[i].val = i+1;
  ListNode *head = &nodes[0];
  print_list(head);
  reverse_print_list(head);
  cout << '\n';
  
  return 0;
}