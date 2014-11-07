// Stack that Support Push, Pop, and GetMin in Constant Time
// http://leetcode.com/2010/11/stack-that-supports-push-pop-and-getmin.html

#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

class MinStack {
public:
  void push(int x) {
    stack.push_back(x);
    if (mins.empty() || x <= mins.back()) {
      mins.push_back(x);
    }
  }

  void pop() {
    assert(!stack.empty());
    int x = stack.back();
    stack.pop_back();
    if (x == mins.back()) {
      mins.pop_back();
    }
  }

  bool empty() const {
    return stack.empty();
  }

  int top() const {
    assert(!stack.empty());
    return stack.back();
  }

  int size() const {
    return stack.size();
  }

  int min() const {
    return mins.back();
  }

private:
  vector<int> stack;
  vector<int> mins;
};

int main(int argc, char const *argv[]) {
  vector<int> arr = {4, 3, 5, 1, 6, 2};
  MinStack stack;
  for (auto i : arr) {
    stack.push(i);
    cout << "Pushing " << i << ", min = " << stack.min() << "\n";
  }

  while (!stack.empty()) {
    cout << "Popping " << stack.top();
    stack.pop();
    if (!stack.empty())
      cout << ", min = " << stack.min() << "\n";
  }
  return 0;
}