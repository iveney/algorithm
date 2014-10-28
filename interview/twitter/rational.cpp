#include <iostream>
using namespace std;

int gcd(int a, int b) {
  int c;
  while (a != 0) {
    c = a;
    a = b % a;
    b = c;
  }
  return b;
}

int lcm(int m, int n)
{
  return m / gcd(m, n) * n;
}

int main() {
  int N;
  cin >> N;
  int num = 0, dem = 0;
  cin >> num >> dem;
  for (int i = 1; i < N; ++i)
  {
    int ai, bi;
    cin >> ai >> bi;
    int l = lcm(dem, bi);
    num *= (l / dem);
    dem = l;
    ai *= (l / bi);
    num += ai;
  }
  int g = gcd(num, dem);
  // cout << num << " " << dem << "\n";
  // cout << g << "\n";
  num /= g;
  dem /= g;
  cout << num << " " << dem;
  return 0;
}