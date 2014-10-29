// http://www.glassdoor.com/Interview/-Given-an-array-of-integers-eg-1-2-3-1-find-whether-there-is-a-sub-sequence-that-sums-to-0-and-return-it-eg-1-2-3-o-QTN_415470.htm

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

pair<int, int> subsequence_sum_zero(vector<int> &arr) {
  unordered_map<int, int> m;
  int sum = 0;
  for (int i = 0; i < arr.size(); ++i) {
    if (arr[i] == 0) {
      return make_pair(i, i);
    }
    sum += arr[i];
    if (m.find(sum) != m.end()) {
      return make_pair(m[sum] + 1, i);
    }
    m[sum] = i;
  }
  return make_pair(-1, -1);
}

int main(int argc, char const *argv[]) {
  // vector<int> arr {1, 2, 1, -3, 4};
  vector<int> arr {1, 2, 1, -3, 4};
  auto p = subsequence_sum_zero(arr);
  cout << p.first << ", " << p.second << "\n";
  return 0;
}