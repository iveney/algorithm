#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <vector>
#include <mutex> 
#include <algorithm>

using namespace std;

const int nthread = 10;
mutex mtx;        // for synchronzied IO
atomic<int> counter (0);
vector<int> call_count(nthread);

void increment_count(int thread_id) {
  // auto id = this_thread::get_id();
  while (counter < 100) {
    this_thread::sleep_for(chrono::seconds(rand() % 5));
    mtx.lock();
    cout << "Thread " << thread_id << " incrementing counter to " << ++counter << endl;
    ++call_count[thread_id];
    mtx.unlock();
  }
}

int main(int argc, char const *argv[])
{
  vector<thread> pool;
  for (int i = 0; i < nthread; ++i) {
    pool.push_back(thread(increment_count, i));
  }

  for (int i = 0; i < nthread; ++i) {
    pool[i].join();
  }

  cout << "Call count for threads:\n";
  copy(call_count.begin(), call_count.end(), 
    ostream_iterator<decltype(call_count)::value_type>(cout, " "));
  cout << '\n';
  return 0;
}