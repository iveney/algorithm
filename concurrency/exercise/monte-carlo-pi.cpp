#include <iostream>
#include <future>
#include <random>
using namespace std;

double monte_carlo(int times) {
  default_random_engine generator;
  uniform_real_distribution<float> distribution(0,1.0);
  size_t count = 0;
  for (int i = 0; i < times; ++i)
  {
    double x = distribution(generator);
    double y = distribution(generator);
    if (x*x + y*y <= 1.0) {
      ++count;
    }
  }
  cout << "Finish computation\n";
  return 4.0 * count / times;
}

int main(int argc, char const *argv[])
{
  int times = 100000000;

  cout << "Creating async\n";
  auto res = async(std::launch::async, monte_carlo, times);

  // never execute if deferred
  // auto res = async(std::launch::deferred, monte_carlo, times);
  cout << "After creating\n";

  cout << "Result is " << res.get() << endl;
  return 0;
}