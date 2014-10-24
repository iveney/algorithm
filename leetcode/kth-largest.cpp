#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "leetcode.h"

// QuickSelect algorithm to find the nth largest element in an unsorted array
// this version have extra memory usage as it does not mutate the original array
int kth_largest(const vector<int> &arr, int k) {
  if (k < 0 || k >= arr.size()) return -1;

  srand(time_t());
  int pivot = arr[rand() % arr.size()];

  // partition. Note that we do *not* add pivot into any array
  vector<int> L;
  vector<int> R;
  for (auto x : arr) {
    if (x < pivot) {
      L.push_back(x);
    } else if (x > pivot) {
      R.push_back(x);
    }
  }

  // select
  if (k + 1 <= L.size()) {
    // it's in L
    return kth_largest(L, k);
  } else if (k + 1 > arr.size() - R.size()) {
    // it's in R
    return kth_largest(R, k - (arr.size() - R.size()));
  } else {
    // pivot itself
    return pivot;
  }
}

int main(int argc, char const *argv[]) {
  vector<vector<int>> arrs {
    {1,5, 6, 1,2, 3, 4, 5},
    {2, 4, 1,2, 1,1,1, 4, 6},
    {8,7,6,5,4,4,3,2,1,},
    {1,2,3,4,5,6,7,8},
    {1},
  };

  vector<int> ks {
    3,
    4,
    5,
    3,
    0,
  };

  for (int i = 0; i < arrs.size(); ++i) {
    cout << "Test  : " << kth_largest(arrs[i], ks[i]) << "\n";
    nth_element(arrs[i].begin(), arrs[i].begin() + ks[i], arrs[i].end());
    cout << "Golden: " << arrs[i][ks[i]] << "\n";
  }
  return 0;
}