// Demonstration of finding median of running numbers
// using two heaps (max + min)

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

const int HEAP_SIZE = 100;
const int MAX_NUM = 1000;

int main(int argc, char const *argv[])
{
  // bootstrap
  vector<int> max_heap;
  vector<int> min_heap;

  double median = 0;
  vector<int> arr = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};;
  for(auto num : arr) {
    // int num = rand() % MAX_NUM;

    if (max_heap.size() == min_heap.size()) {
      if (num <= median) {
        max_heap.push_back(num);
        push_heap(max_heap.begin(), max_heap.end());
        median = max_heap.front();
      } else {
        min_heap.push_back(num);
        push_heap(min_heap.begin(), min_heap.end(), greater<int>());
        median = min_heap.front();
      }
    } else if (max_heap.size() > min_heap.size()) {
      if (num <= median) {
        // inserts into max heap: balance the heaps
        pop_heap(max_heap.begin(), max_heap.end());
        int top = max_heap.back();
        max_heap.pop_back();
        max_heap.push_back(num);
        push_heap(max_heap.begin(), max_heap.end());

        min_heap.push_back(top);
        push_heap(min_heap.begin(), min_heap.end(), greater<int>());
      } else {
        // inserts into min heap: now they balanced
        min_heap.push_back(num);
        push_heap(min_heap.begin(), min_heap.end(), greater<int>());
      }
      median = (max_heap.front() + min_heap.front()) / 2.0;
    } else {// max heap has less element than min heap
      if (num <= median) {
        // inserts into max heap
        max_heap.push_back(num);
        push_heap(max_heap.begin(), max_heap.end());
      } else {
        // pop an element from min to max heap, inserts into min heap
        pop_heap(min_heap.begin(), min_heap.end(), greater<int>());
        int top = min_heap.back();
        min_heap.pop_back();
        min_heap.push_back(num);
        push_heap(min_heap.begin(), min_heap.end(), greater<int>());

        max_heap.push_back(top);
        push_heap(max_heap.begin(), max_heap.end());
      }
      median = (max_heap.front() + min_heap.front()) / 2.0;
    }

    cout << "Element: " << num << ", median: " << median << endl;
  }
  return 0;
}