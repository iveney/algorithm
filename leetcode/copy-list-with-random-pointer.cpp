#include "leetcode.h"

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
    typedef unordered_map<RandomListNode *, RandomListNode *> Map;
    Map map;

    RandomListNode *getOrCreateNode(RandomListNode *p) {
      if (p == NULL) return NULL;
      RandomListNode *node = map[p];
      if (!node) {
        // not exist, create a corresponding node
        node = new RandomListNode(p->label);
        map[p] = node;
      }
      return node;
    }

public:

  RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode *dup = NULL, *tail = NULL;
    RandomListNode *p = head;
    while (p != NULL) {
      RandomListNode *node = getOrCreateNode(p);
      RandomListNode *random = getOrCreateNode(p->random);
      node->random = random;

      if (dup == NULL) {
        dup = tail = node;
      } else {
        tail->next = node;
        tail = tail->next;
      }
      p = p->next;
    }

    return dup;
  }
};

int main() {
  Solution sol;
  
  return 0;
}