#include <cassert>
#include <deque>
#include <queue>
#include <iostream>
using namespace std;

class MinQueue {
public:
  void push(int x) {
    q.push(x);
    while (!mins.empty() && mins.back() > x) {
      mins.pop_back();
    }
    mins.push_back(x);
  }

  void pop() {
    assert(!q.empty());
    if (mins.front() == q.front()) {
      mins.pop_front();
    }
    q.pop();
  }

  int front() const {
    return q.front();
  }

  int size () const {
    return q.size();
  }

  bool empty() const {
    return q.empty();
  }

  int min() const {
    assert(!mins.empty());
    return mins.front();
  }

private:
  queue<int> q;
  deque<int> mins;
};

int main(int argc, char const *argv[]) {
  vector<int> arr = {4, 3, 5, 1, 6, 2};
  MinQueue q;
  for (auto i : arr) {
    q.push(i);
    cout << "Pushing " << i << ", min = " << q.min() << "\n";
  }

  while (!q.empty()) {
    cout << "Popping " << q.front();
    q.pop();
    if (!q.empty())
      cout << ", min = " << q.min() << "\n";
  }
  return 0;
}