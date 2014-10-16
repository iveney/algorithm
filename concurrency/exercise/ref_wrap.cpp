#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> v;
  int a = 1, b = 2;
  v.push_back(std::ref(a));
  v.push_back(b);
  ++v[0];

  cout << a << " : " << b << endl;
  return 0;
}