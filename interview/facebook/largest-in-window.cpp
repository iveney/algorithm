#include <vector>
#include <deque>
#include <iostream>
using namespace std;

class MaxQueue {
public:
  void push_back(int x) {
    while (!maxQ.empty() && maxQ.back() < x) {
      // new element renders all these elements not useful
      maxQ.pop_back();
    }
    Q.push_back(x);
    maxQ.push_back(x);
  }

  void pop_front() {
    if (Q.empty()) return;

    int front = Q.front();
    if (front == maxQ.front())
      maxQ.pop_front();
    Q.pop_front();
  }

  int get_max() {
    return maxQ.front();
  }

  int size() {return Q.size();}

  typedef deque<int> Deque;
  Deque Q, maxQ;
};

vector<int> largest_in_window(vector<int> &array, int wsize) {
  vector<int> result;
  MaxQueue Q;

  // initialize
  int i;
  int current_max;
  for (auto x : array) {
    if (Q.size() < wsize)
      // window not full
      Q.push_back(x);
    else {
      // maintain window
      Q.pop_front();
      Q.push_back(x);
    }

    if (Q.size() == wsize)
      result.push_back(Q.get_max());
  }

  return result;
}

int main(int argc, char const *argv[])
{
  vector<int> array{6,5,10,3,6,2,2,1,1,1,7,3,4,};
  int wsize = 4;
  auto result = largest_in_window(array, wsize);
  copy(result.begin(), result.end(), 
    ostream_iterator<decltype(result)::value_type>(cout, " "));
  cout << '\n';
  return 0;
}