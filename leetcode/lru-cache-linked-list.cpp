#include "leetcode.h"

struct DoubleLinkList {
  DoubleLinkList(int k, int v): key(k), value(v), pred(NULL), next(NULL) {}
  int key;
  int value;
  DoubleLinkList *pred, *next;
};

ostream & operator << (ostream& os, const DoubleLinkList *list) {
  return (os << '(' << list->key << ", " << list->value << ')');
}

class LRUCache{
public:
  LRUCache(int capacity) {
    size = 0;
    cap = capacity;
    head = tail = NULL;
  }

  void pop_front() {
    if (head != NULL) {
      DoubleLinkList *next = head->next;
      map.erase(head->key);
      delete head;
      head = next;
    }
    --size;
  }

  void push_back(int key, int value) {
    DoubleLinkList *node = new DoubleLinkList(key, value);
    map[key] = node;

    if (head == NULL) {
      head = tail = node;
    } else {
      tail->next = node;
      node->pred = tail;
      tail = node;
    }
    ++size;
  }

  // move the node to the end of list
  void update_list (DoubleLinkList *node) {
    DoubleLinkList *pred = node->pred;
    DoubleLinkList *next = node->next;

    if (node == tail) {
      return;
    }

    if (node == head) {
      head = next;
      head->pred = NULL;
    } else {
      pred->next = next;
      next->pred = pred;
    }

    tail->next = node;
    node->pred = tail;
    tail = node;
    tail->next = NULL;
  };

  int get(int key) {
    auto it = map.find(key);
    if (it == map.end()) {
      return -1;
    }

    // update most recently used item in cache by
    // moving the item to back of list
    update_list(it->second);

    return it->second->value;
  }

  void set(int key, int value) {
    auto it = map.find(key);
    if (it == map.end()) {
      // insert new item
      if (size == cap) {
        // full, remove the least recently used item from list front
        pop_front();
      }
      push_back(key, value);
    } else {
      // update existing item
      update_list(it->second);
      it->second->value = value;
    }
  }

// private:
  DoubleLinkList *head, *tail;
  unordered_map<int, DoubleLinkList *> map;
  int size;
  int cap;
};

int main() {
  LRUCache cache(10);
  cache.set(10,13);
  cache.set(3,17);
  cache.set(6,11);
  cache.set(10,5);
  cache.set(9,10);
  cache.get(13);
  cache.set(2,19);
  cache.get(2);
  cache.get(3);
  cache.set(5,25);
  cache.get(8);
  cache.set(9,22);
  cache.set(5,5);
  cache.set(1,30);
  cache.get(11);
  cache.set(9,12);
  cache.get(7);
  cache.get(5);
  cache.get(8);
  cache.get(9);
  cache.set(4,30);
  cache.set(9,3);
  cache.get(9);
  cache.get(10);
  cache.get(10);
  cache.set(6,14);
  cache.set(3,1);
  cache.get(3);
  cache.set(10,11);
  cache.get(8);
  cache.set(2,14);
  cache.get(1);
  cache.get(5);
  cache.get(4);
  cache.set(11,4);
  cache.set(12,24);
  cache.set(5,18);
  cache.get(13);
  cache.set(7,23);
  cache.get(8);
  cache.get(12);
  cache.set(3,27);
  cache.set(2,12);
  cache.get(5);
  cache.set(2,9);
  cache.set(13,4);
  cache.set(8,18);
  cache.set(1,7);
  cache.get(6);
  cache.set(9,29);
  cache.set(8,21);
  cache.get(5);
  cache.set(6,30);
  cache.set(1,12);
  cache.get(10);
  cache.set(4,15);
  cache.set(7,22);
  cache.set(11,26);
  cache.set(8,17);
  cache.set(9,29);
  cache.get(5);
  cache.set(3,4);
  cache.set(11,30);
  cache.get(12);
  cache.set(4,29);
  cache.get(3);
  cache.get(9);
  cache.get(6);
  cache.set(3,4);
  cache.get(1);
  cache.get(10);
  cache.set(3,29);
  cache.set(10,28);
  cache.set(1,20);
  cache.set(11,13);
  cache.get(3);
  cache.set(3,12);
  cache.set(3,8);
  cache.set(10,9);
  cache.set(3,26);
  cache.get(8);
  cache.get(7);
  cache.get(5);
  cache.set(13,17);
  cache.set(2,27);
  cache.set(11,15);
  cache.get(12);
  cache.set(9,19);
  cache.set(2,15);
  cache.set(3,16);
  cache.get(1);
  cache.set(12,17);
  cache.set(9,1);
  cache.set(6,19);
  cache.get(4);
  cache.get(5);
  cache.get(5);
  cache.set(8,1);
  cache.set(11,7);
  cache.set(5,2);
  cache.set(9,28);
  cache.get(1);
  cache.set(2,2);
  cache.set(7,4);
  cache.set(4,22);
  cache.set(7,24);
  cache.set(9,26);
  cache.set(13,28);
  cache.set(11,26);

  DoubleLinkList *node = cache.head;
  while(node != NULL) {
    cout << node << " ";
    node = node->next;
  }
  cout << '\n';

  return 0;
}