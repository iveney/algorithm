#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int sum = 0;

// race condition: different thread may assign value to sum and overwrite
void square(int x) {
  int sq = x * x;
  sum = sum + sq;
}

int main(int argc, char const *argv[]) {
  vector<thread> pool;
  for (int i = 1; i <= 30; ++i) {
    pool.push_back(thread(&square, i));
  }
  for (auto &th : pool) {
    th.join();
  }
  cout << sum << endl;
  return 0;
}