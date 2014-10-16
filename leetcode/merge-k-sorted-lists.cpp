// another idea is to use mergesort, which merges two lists together
#include "leetcode.h"

namespace std{
template <>
class less<ListNode *> {
public:
  bool operator () (ListNode *a, ListNode *b) const {
    if (a == nullptr) return false;
    if (b == nullptr) return true;
    return a->val > b->val;
  }
};
}

// use priorty queue to maintain n minimum elements
class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *head = nullptr, *tail = nullptr;
    priority_queue<ListNode *> q(std::less<ListNode *>(), lists);

    while (!q.empty()) {
      ListNode *node = q.top();
      q.pop();
      if (node == nullptr) {
        continue;
      }
      if (head == nullptr) {
        head = tail = node;
      } else {
        tail->next = node;
        tail = node;
      }
      node = node->next;
      if (node) {
        q.push(node);
      }
    } // while

    return head;
  }
};

// This code does not work anymore: causes TLE
class SolutionSelectionSort {
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

// Use C++11 style, but it causes TLE
class SolutionSTL {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    int n = lists.size();
    if (n == 0) return nullptr;

    ListNode *head = nullptr, *tail = nullptr;
    while(true) {
      auto min_node = std::min_element(lists.begin(), lists.end(),
        [](ListNode *a, ListNode *b){
          if (a == nullptr) return false;
          if (b == nullptr) return true;
          return a->val < b->val;
      });
      if (*min_node == nullptr) {
        break;
      }
      // cout << "Current min = " << *min_node << " " << (*min_node)->val << endl;
      if (head == nullptr) {
        head = tail = *min_node;
      } else {
        tail->next = *min_node;
        tail = tail->next;
      }
      *min_node = (*min_node)->next;
      tail->next = nullptr;
    }

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

  vector<ListNode*> v;
  v.push_back(NULL);
  head = sol.mergeKLists(v);
  print_list(head);

  return 0;
}