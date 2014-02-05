#include <iostream>
using namespace  std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
      ListNode *p = l1, *q = l2, *cur = NULL;
      ListNode *head = NULL;
      if (l1 == NULL) {
        head = l2;
        return head;
      } else if (l2 == NULL) {
        head = l1;
        return head;
      }
      bool done = false;
      while (p!=NULL && q!=NULL) {
        if (p->val > q->val) {
          // point to q
          if (cur != NULL) {
            cur->next = q;
          } else {
            head = q;
          }
          cur = q;
          q = q->next;
        } else {
          // point to p
          if (cur != NULL) {
            cur->next = p;
          } else {
            head = p;
          }
          cur = p;
          p = p->next;
        }
      } // while

      // cur points to tail, point to the remaining
      if (p==NULL) {
        cur->next = q;
      }
      else if (q==NULL) {
        cur->next = p;
      }
      else
        cur->next = NULL;

      return head;
    }
};

void output_list(ListNode* head) {
  ListNode* p = head;
  while(p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
}

int main(int argc, char const *argv[])
{
  const int n1=5;
  ListNode a[n1];
  for (int i = 0; i < n1; ++i)
  {
    a[i].val = (i+1)*10;
    if (i < n1-1)
      a[i].next = &a[i+1];
  }

  const int n2=6;
  ListNode b[n2];
  for (int i = 0; i < n2; ++i)
  {
    b[i].val = (i+1)*6;
    if (i < n2-1)
      b[i].next = &b[i+1];
  }

  ListNode* l1 = &a[0];
  ListNode* l2 = &b[0];

  // special case
  l1 = NULL;
  l2 = NULL;

  output_list(l1);
  output_list(l2);

  Solution sol;
  ListNode* head = sol.mergeTwoLists(l1, l2);
  output_list(head);
  return 0;
}