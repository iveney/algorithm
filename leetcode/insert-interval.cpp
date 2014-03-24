#include "leetcode.h"


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> merged;
    bool done = false;
    for (auto itv : intervals) {
      if (done) {
        merged.push_back(itv);
        continue;
      }

      if (newInterval.end < itv.start) {
        // new interval inserted before this, just copy the rest
        merged.push_back(newInterval);
        merged.push_back(itv);
        done = true;
      } else if (newInterval.start > itv.end) {
        // new interval after this
        merged.push_back(itv);
      } else {
        // new interval overlap with this
        newInterval.start = min(newInterval.start, itv.start);
        newInterval.end = max(newInterval.end, itv.end);
      }
    } // for

    if (!done)
      merged.push_back(newInterval);

    return merged;
  }
};

int main() {
  Solution sol;

  vector<vector<Interval> > Intervals {
    {{1,3},{6,9}},
    {{1,2},{3,5},{6,7},{8,10},{12,16}},
    {},
    {{3, 5}, {10, 15}},
    {{3, 5}, {10, 15}},
    {{3, 5}, {10, 15}},
    {{3, 5}, {10, 15}},
  };

  vector<Interval> newInterval {
    {2,5},
    {4,9},
    {1,4},
    {1,2},
    {6,7},
    {16,18},
    {1,20},
  };

  for (int i = 0; i < Intervals.size(); ++i)
  {
    auto result = sol.insert(Intervals[i], newInterval[i]);
    for (auto itv : result) {
      printf("[%d, %d] ", itv.start, itv.end);
    }
    printf("\n");
  }
  
  return 0;
}