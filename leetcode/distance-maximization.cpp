// http://leetcode.com/2011/05/a-distance-maximizing-problem.html

#include <random>
#include "leetcode.h"

int brute_force(vector<int> &arr) {
  int n = arr.size();
  int nmax = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (arr[i] < arr[j]) {
        nmax = max(nmax, j - i);
      }
    }
  }
  return nmax;
}

int linear(vector<int> &arr) {
  int n = arr.size();
  int nmax = 0;
  // idx of decreasing sequence left to right
  vector<int> start;
  // idx of increasing sequence right to left
  vector<int> end;
  start.push_back(0);
  end.push_back(n-1);
  for (int i = 1; i < n; ++i) {
    if (arr[i] < arr[start.back()]) {
      start.push_back(i);
    }
    if (arr[n-i-1] > arr[end.back()]) {
      end.push_back(n-i-1);
    }
  }

  int a = 0, b = end.size() - 1;
  while (a < start.size() && b >= 0) {
    if (start[a] >= end[b]) {
      --b;
    } else if (arr[start[a]] < arr[end[b]]) {
      nmax = max(nmax, end[b] - start[a]);
      --b;
    } else {
      ++a;
    }
  }
  return nmax;
}

int main() {
  int N = 1000;
  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    arr[i] = i;
  }
  std::random_device rd;
  std::mt19937 g(rd());
  for (int i = 0; i < N; ++i) {
    shuffle(arr.begin(), arr.end(), g);
    int ma = brute_force(arr);
    int mb = linear(arr);
    if (ma != mb) {
      copy(arr.begin(), arr.end(), 
        ostream_iterator<decltype(arr)::value_type>(cout, " "));
      cout << "\n";
    }
  }
  
  return 0;
}
