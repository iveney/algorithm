#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <chrono>
#include <queue>
#include <atomic>
using namespace std;

int main() {
  atomic_int c(0);
  bool done = false;
  queue<int> goods;

  thread producer([&]() {
    for (int i = 0; i < 500; ++i) {
      goods.push(i);
      c++;
    }

    done = true;
  });

  thread consumer([&]() {
    while (!done) {
      while (!goods.empty()) {
        goods.pop();
        c--;
      }
    }
  });

  producer.join();
  consumer.join();
  cout << "Net: " << c << endl;
  cout << "Goods: " << goods.size() << endl;
  return 0;
}