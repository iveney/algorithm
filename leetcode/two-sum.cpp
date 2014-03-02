#include <unordered_map>
#include "leetcode.h"

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    unordered_map<int, int> idx;
    for (int i = 0; i < numbers.size(); ++i) {
      idx[numbers[i]] = i;
    }

    for (int i = 0; i < numbers.size(); ++i)
    {
      int r = target - numbers[i];
      int j;
      if (idx.find(r) != idx.end() && (j = idx[r]) != i) {
        int j = idx[r];
        if (i > j)
          swap(i, j);
        return vector<int> {i+1, j+1};
      }
    }
    return vector<int>{0, 0};
  }
};

int main() {
  Solution sol;
  // vector<int> numbers{2, 7, 11, 15};
  // vector<int> numbers{7, 2, 11, 15};
  vector<int> numbers{3,2,4};
  int target = 6;
  auto result = sol.twoSum(numbers, target);
  printf("%d %d\n", result[0], result[1]);
  return 0;
}