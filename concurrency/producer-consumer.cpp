#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <chrono>
#include <queue>
using namespace std;

std::mutex m;

int main() {
  int c = 0;
  bool done = false;
  queue<int> goods;

  thread producer([&]() {
    for (int i = 0; i < 500; ++i) {
      goods.push(i);
      m.lock();
      c++;
      m.unlock();
    }

    done = true;
  });

  thread consumer([&]() {
    while (!done) {
      while (!goods.empty()) {
        goods.pop();
        m.lock();
        c--;
        m.unlock();
      }
    }
  });

  producer.join();
  consumer.join();
  cout << "Net: " << c << endl;
  cout << "Goods: " << goods.size() << endl;
  return 0;
}