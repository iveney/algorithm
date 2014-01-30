// http://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/

#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
      ListNode *p = head, *q = NULL;
      while(p != NULL) {
        q = p->next;
        if (q == NULL)
          break;

        if (q->val != p->val) {
          p = q;
        } else {
          // remove node at q
          ListNode *r = q->next;
          p->next = r;
          delete q;
          q = NULL;
        }
      }
      return head;
    }
};

ListNode* list_from_arrary(int *array, int n) {
  if (n == 0) return NULL;
  ListNode *head = new ListNode(array[0]);
  ListNode *p = head;
  for (int i = 1; i < n; ++i) {
    ListNode *q = new ListNode(array[i]);
    p->next = q;
    p = q;
  }
  return head;
}

void output_list(ListNode* head) {
  ListNode* p = head;
  while(p!=NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
}

int main(int argc, char const *argv[])
{
  int a[] = {1, 1, 2};
  int b[] = {1, 1, 2, 3, 3};
  int c[] = {1, 1, 1};
  Solution sol;

  ListNode *head = NULL;
  head = list_from_arrary(a, 3);
  output_list(head);
  sol.deleteDuplicates(head);
  output_list(head);

  head = list_from_arrary(b, 5);
  output_list(head);
  sol.deleteDuplicates(head);
  output_list(head);

  head = list_from_arrary(c, 3);
  output_list(head);
  sol.deleteDuplicates(head);
  output_list(head);
  
  sol.deleteDuplicates(NULL);
  return 0;
}