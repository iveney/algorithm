#include "leetcode.h"

class Solution {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    if (n == 0)
      return 0;

    if (n == 1)
      return 1;

    vector<int> counts(n, 0);
    // pass 1: left to right
    // initial case
    int sum = 0;
    int prev = 1;
    if (ratings[1] >= ratings[0]) {
      sum += 1;
      counts[0] = 1;
    }
    for (int i = 1; i < n; ++i) {
      if (ratings[i] > ratings[i-1]) {
        // going up
        ++prev;
        sum += prev;
        counts[i] = prev;
      } else {
        prev = 1;
        if (ratings[i] == ratings[i-1]) {
          // flat
          sum += prev;
          counts[i] = prev;
        }
      }
    }

    // pass 2: right to left
    prev = 1;
    if (ratings[n-2] > ratings[n-1]) {
      sum += 1;
      counts[n-1] = 1;
    }
    for (int i = n-2; i >= 0; --i) {
      if (ratings[i] > ratings[i+1]) {
        // going up
        ++prev;
        // note that if this is a peak, we need to take max
        if (counts[i] > 0) {
          int m = max(counts[i], prev);
          sum += m - counts[i];
          counts[i] = m;
        } else {
          sum += prev;
          counts[i] = prev;
        }
      } else {
        prev = 1;
        if (counts[i] == 0) {
          // this is a plateu
          counts[i] = 1;
          sum += 1;
        }
      }
    }

    copy(counts.begin(), counts.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return sum;
  }
};

int main() {
  vector<vector<int> > vec = {
    // {1,2,3,4,2,1},
    // {1,2,3,3,3,3},
    // {3,2,1,2,3,3},
    // {2,2,2,2,2},
    {3,4,4,4,3},
  };
  Solution sol;
  for (auto &ratings : vec) {
    cout << sol.candy(ratings) << endl;
  }
  
  return 0;
}