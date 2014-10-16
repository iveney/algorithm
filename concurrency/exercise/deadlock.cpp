#include <thread>
#include <mutex>
#include <iostream>

std::mutex kettle, tap;

#define THREAD_POOL 8

void kettle_tap() {
  std::lock(kettle, tap);
  std::lock_guard<std::mutex> kettle_lock(kettle, std::adopt_lock);
  std::lock_guard<std::mutex> tap_lock(tap, std::adopt_lock);

  std::cout << "Locking kettle in " << std::this_thread::get_id() << std::endl;
  // std::lock_guard<std::mutex> kettle_lock(kettle);
  std::cout << "Locked kettle in " << std::this_thread::get_id() << std::endl;
  
  std::cout << "Locking tap in " << std::this_thread::get_id() << std::endl;
  // std::lock_guard<std::mutex> tap_lock(tap);
  std::cout << "Locked tap in " << std::this_thread::get_id() << std::endl;
  
  std::cout << "Filling kettle in " << std::this_thread::get_id() << std::endl;
}

void tap_kettle() {
  std::lock(tap, kettle);
  std::lock_guard<std::mutex> kettle_lock(kettle, std::adopt_lock);
  std::lock_guard<std::mutex> tap_lock(tap, std::adopt_lock);

  std::cout << "Locking tap in " << std::this_thread::get_id() << std::endl;
  // std::lock_guard<std::mutex> tap_lock(tap);
  std::cout << "Locked tap in " << std::this_thread::get_id() << std::endl;
  
  std::cout << "Locking kettle in " << std::this_thread::get_id() << std::endl;
  // std::lock_guard<std::mutex> kettle_lock(kettle);
  std::cout << "Locked kettle in " << std::this_thread::get_id() << std::endl;
  
  std::cout << "Filling kettle in " << std::this_thread::get_id() << std::endl;
}


int main() {
  std::thread pool[THREAD_POOL];

  for (int t=0; t<THREAD_POOL; t+=2) {
    pool[t] = std::thread(kettle_tap);
    pool[t+1] = std::thread(tap_kettle);
  }

  for (int t=0; t<THREAD_POOL; ++t)
    pool[t].join();

  std::cout << "Threads are all joined" << std::endl;

  return 0;
}