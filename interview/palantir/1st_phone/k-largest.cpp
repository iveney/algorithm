// Given an infinite stream, keep the k largest integers
#include <iostream>
#include <vector>
using namespace std;

class Heap {
public:
  Heap(int size) {data.resize(size);}
  bool empty() const {return current_size == 0;}
  bool full() const {return current_size == data.size();}

  int top() {
    if (!empty())
      return data.front();
    return 0;
  }

  // return true is succesfully inserted
  bool insert(int val) {
    if (full()) return false;

    // bubble up
    int p = current_size;
    data[p] = val;
    while (p > 0 && data[p] < data[(p-1)/2]) {
      swap(data[p], data[(p-1)/2]);
      p = (p-1) / 2;
    }
    ++current_size;
    return true;
  }

  // return true is succesfully popped
  bool pop() {
    if (empty()) return false;

    int p = 0;
    data[p] = data[current_size-1];
    --current_size;
    while (p < current_size) {
      int l = (p+1) * 2 - 1;
      int r = (p+1) * 2;
      if (l < current_size && data[p] > data[l]) {
        if (r < current_size && data[l] > data[r]) {
          swap(data[r], data[p]);
          p = r;
        } else {
          swap(data[l], data[p]);
          p = l;
        }
      } else {
        break;
      }
    } // while
    return true;
  }

  size_t size() const {return current_size;}

  vector<int> output() {
    vector<int> result;
    while (!empty()) {
      result.push_back(top());
      pop();
    }
    return result;
  }

private:
  size_t current_size;
  vector<int> data;
};


int main(int argc, char const *argv[])
{
  vector<int> stream {
    10,52,4,84,23,72,75,6,1,5,6,356,24,26,7,2,465,1,3,45,
  };

  // say we keep the top 5
  int K = 5;
  Heap heap(7); // create a heap larger than 5

  for (auto v : stream) {
    if (heap.empty())
      heap.insert(v);
    else if (v > heap.top()) {
      if (heap.size() == K)
        heap.pop();
      heap.insert(v);
    }
  }

  auto result = heap.output();
  copy(result.rbegin(), result.rend(), 
    ostream_iterator<decltype(result)::value_type>(cout, " "));
  cout << '\n';

  // compare with the sorted list
  sort(stream.begin(), stream.end(), [](int a, int b) {
    return a > b;
  });
  copy(stream.begin(), stream.begin() + K, 
    ostream_iterator<decltype(stream)::value_type>(cout, " "));
  cout << '\n';
  return 0;
}