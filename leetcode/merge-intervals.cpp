#include "leetcode.h"

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

// class IntervalTree {
// public:
//   IntervalTree(Interval itv) : interval(itv), left(NULL), right(NULL) {}

//   void insert(Interval itv) {

//   }

//   Interval interval;
//   Interval *left, *right;
// };

class Solution {
public:
  vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.empty()) return intervals;

    sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
      if (a.start == b.start)
        return a.end < a.end;
      return a.start < b.start;
    });

    vector<Interval> merged;
    Interval prev = intervals[0];
    for (int i = 1; i < intervals.size(); ++i) {
      Interval curr = intervals[i];
      if (curr.start <= prev.end) {
        // merge
        prev.end = max(prev.end, curr.end);
      } else {
        // split
        merged.push_back(prev);
        prev = curr;
      }
    }
    // push the last into
    merged.push_back(prev);
    return merged;
  }
};

int main() {
  Solution sol;
  vector<Interval> intervals {
    {1,3},{2,6},{8,10},{15,18},
  };
  
  auto merged = sol.merge(intervals);
  for (auto itv : merged) {
    printf("[%d, %d] ", itv.start, itv.end);
  }
  printf("\n");

  return 0;
}