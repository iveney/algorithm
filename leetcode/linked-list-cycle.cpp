#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *p = head, *q = head;
    while (p != NULL && q != NULL) {
      p = p->next;
      q = q->next;
      if (p == NULL || q == NULL)
        break;
      if (q != NULL)
        q = q->next;
      if (p == q)
        return true;
    }
    return false;
 }
};

int main(int argc, char const *argv[])
{
  ListNode nodes[] = {ListNode(0), ListNode(1), ListNode(2),
                      ListNode(3), ListNode(4), ListNode(5)};
  for (int i = 0; i < 5; ++i) {
    nodes[i].next = &nodes[i+1];
  }
  nodes[5].next = &nodes[2];

  Solution sol;
  cout << sol.hasCycle(&nodes[0]) << endl;

  nodes[1].next = NULL;
  cout << sol.hasCycle(&nodes[0]) << endl;
  cout << sol.hasCycle(&nodes[1]) << endl;
  cout << sol.hasCycle(NULL) << endl;

  cout << sol.hasCycle(&nodes[2]) << endl;
  cout << sol.hasCycle(&nodes[3]) << endl;
  return 0;
}