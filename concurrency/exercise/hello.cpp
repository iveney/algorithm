#include <thread>
#include <vector>
#include <mutex>
#include <iostream>
using namespace std;

mutex m;

// need to apply mutex, otherwise the output is interleaved.
// or use a lock_guard
void say_hello() {
  lock_guard<mutex> my_lock(m);
  // m.lock();
  cout << "Hello from " << this_thread::get_id() << endl;
  // m.unlock();
}

int main(int argc, char const *argv[]) {
  const int num_threads = 10;
  std::vector<thread> threads;

  for (int i = 0; i < num_threads; ++i) {
    threads.push_back(thread(&say_hello));
  }

  for (auto &thread : threads) {
    thread.join();
  }

  return 0;
}