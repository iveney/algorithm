#include <iostream>
#include <string>
#include <thread>
#include <limits>
#include <thread>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void func(string identifier) {
  cout << "Inside func\n";
  for (int i = 0; i < std::numeric_limits<int>::max(); ++i) {
    if (i % 100000000 == 0) {
      cout << identifier << ": i = " << i << "\n";
    }
  }
  cout << "End of func\n";
}

int main(int argc, char const *argv[])
{
  cout << "About to create thread object\n";
  vector<std::thread> threads;
  for (int i = 0; i < 4; ++i) {
    threads.push_back(std::thread(&func, std::to_string(i)));
  }
  cout << "After creating thread object\n";
  for (auto &th : threads) {
    th.join();
  }
  return 0;
}