#include <iostream>
#include <vector>
using namespace std;

struct KeyValue {
  int key, value;
};

class HashMap {
public:
  HashMap(int cap = 1024) : capacity(cap), current_size(0) {
    data.resize(cap);
  }
  ~HashMap(){}

  int hash(int key) {return (key*2654435761) % capacity;}

  KeyValue* get(int key) {
    int idx = hash(key);
    int p = idx;
    // linear probe
    while (p < capacity && data[p] != NULL && data[p]->key != key) {
      ++p;
    }

    // p == NULL when: 1. key not exist 2. linear probe failed (map full)
    return data[p];
  }

  bool set(int key, int value) {
    int p = hash(key);
    while (p < capacity && data[p] != NULL) {
      ++p;
    }
    if (p != capacity) {
      data[p] = new KeyValue {key, value};
      return true;
    }
    return false;
  }


  int capacity;
  int current_size;
  vector<KeyValue *> data;
};

int main(int argc, char const *argv[])
{
  HashMap map(1<<4);
  for (int i = 0; i < 10; ++i) {
    int key = ((i * 74234534) >> 1) / 123;
    int value = i;
    map.set(key, value);
  }
  // after insertion, see if we can find it
  for (int i = 0; i < 10; ++i) {
    int key = ((i * 74234534) >> 1) / 123;
    KeyValue * kv = map.get(key);
    if (kv != NULL) 
      cout << kv->key << ", " << kv->value << "   ";
    else
      cout << kv->key << ": fail   ";
  }
  // for (auto kv : map.data) {
  //   if (kv != NULL)
  //     cout << kv->key << ", " << kv->value << "   ";
  //   else
  //     cout << "N, N" << "   ";
  // }
  return 0;
}
