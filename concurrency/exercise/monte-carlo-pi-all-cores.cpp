#include <iostream>
#include <future>
#include <random>
using namespace std;

int monte_carlo(size_t times) {
  default_random_engine generator;
  uniform_real_distribution<float> distribution(0,1.0);
  size_t count = 0;
  for (size_t i = 0; i < times; ++i)
  {
    double x = distribution(generator);
    double y = distribution(generator);
    if (x*x + y*y <= 1.0) {
      ++count;
    }
  }
  return count;
}

int main(int argc, char const *argv[])
{
  size_t num_threads = std::thread::hardware_concurrency();
  cout << "# cores: " << num_threads << endl;

  size_t times = 100000000;
  vector<future<int> > results;
  for (int i = 0; i < num_threads; ++i) {
    results.push_back(async(monte_carlo, times));
  }

  size_t count = 0;
  for (auto &res : results) {
    count += res.get();
  }

  cout << "Count = " << count;
  cout << " Times = " << num_threads * times << endl;
  cout << "Pi = " << 4.0 * count / (num_threads * times) << endl;

  return 0;
}