#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void output(ListNode *head) {
  while(head!=NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

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
  ListNode nodes[] = {
    ListNode(1),
    ListNode(2),
    ListNode(3),
    ListNode(4),
    ListNode(6),
  };
  int n = sizeof(nodes) / sizeof(ListNode);
  for (int i = 0; i < n-1; ++i)
  {
    nodes[i].next = &nodes[i+1];
  }
  Solution sol;
  ListNode *head = &nodes[0];
  output(head);
  ListNode *newhead = sol.swapPairs(head);
  output(newhead);
  return 0;
}