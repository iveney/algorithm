// expected output:
// (6, 19) (8, 1) (5, 2) (1, 20) (2, 2) (4, 22) (7, 24) (9, 26) (13, 28) (11, 26) 

#include <unordered_map>
#include <list>
#include "leetcode.h"

struct CacheItem {
  CacheItem(int k, int v) : key(k), value(v) {}
  int key;
  int value;
  friend ostream & operator << (ostream& os, const CacheItem& ci);
};


ostream & operator << (ostream& os, const CacheItem& ci) {
  return (os << '(' << ci.key << ", " << ci.value << ')');
}

class LRUCache{
public:
  typedef list<CacheItem>::iterator ListIterator;
  typedef unordered_map<int, ListIterator>::iterator MapIterator;
  list<CacheItem> cache;
  unordered_map<int, ListIterator> keys;
  int size;
  int cap;

  LRUCache(int capacity) : cap(capacity), size(0) {}

  CacheItem remove_item(ListIterator li) {
    CacheItem ci = *li;
    cache.erase(li);

    return ci;
  }

  // update the recently used item in hash
  void update_mru() {
    ListIterator li = cache.end();
    advance(li, -1);
    keys[li->key] = li;
  }
  
  // Get the value (will always be positive) of the key if the key exists in
  // the cache, otherwise return -1.
  int get(int key) {
    MapIterator mi = keys.find(key);
    if (mi != keys.end()) {
      CacheItem ci = remove_item(mi->second);
      cache.push_back(ci);
      update_mru();
      return ci.value;
    }

    return -1;
  }
  
  // Set or insert the value if the key is not already present.
  void set(int key, int value) {
    MapIterator mi = keys.find(key);
    CacheItem kv(key, value);
    if (mi != keys.end()) {
      remove_item(mi->second);
    } else {
      if (size == cap) {
        int key_to_erase = cache.front().key;
        keys.erase(key_to_erase);
        cache.pop_front();
      } else {
        ++size;
      }
    }
    cache.push_back(kv);
    update_mru();
  }
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
  list<CacheItem> &item = cache.cache;
  copy(item.begin(), item.end(), 
    ostream_iterator<CacheItem>(cout, " "));
  cout << '\n';

  // int sequence[] = {1, 2, 3, 1, 2, 3, 4, 2,};
  // for (int key: sequence) {
  //   cache.set(key, 0);
  //   cout << key << ": ";
  //   list<CacheItem> &item = cache.cache;
  //   copy(item.begin(), item.end(), 
  //     ostream_iterator<CacheItem>(cout, " "));
  //   cout << '\n';
  // }

  return 0;
}