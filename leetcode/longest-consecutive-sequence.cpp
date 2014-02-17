// can be more concise if we compute the range
#include <unordered_map>
#include "leetcode.h"

class Solution {
public:
  int longestConsecutive(vector<int> &num) {
    int n = num.size();
    if (n <= 1) return n;

    vector<int> parent(n, -1);
    vector<int> child(n, -1);
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
      map[num[i]] = i;
    }

    for (int i = 0; i < n; i++) {
      if (map.find(num[i]+1) != map.end()) {
        int pid = map[num[i]+1];
        parent[i] = pid; 
        child[pid] = i;
      }
    }

    int maxlen = 0;
    vector<int> visited(n, 0);
    // find each chain
    for (int i = 0; i < n; ++i) {
      if (visited[i])
        continue;

      int len = 1;
      int j = i;
      while(parent[j] != -1) {
        visited[j] = 1;
        j = parent[j];
        ++len;
      }

      j = i;
      while (child[j] != -1) {
        visited[j] = 1;
        j = child[j];
        ++len;
      }

      if (len > maxlen)
        maxlen = len;
    } // for
    return maxlen;
  }
};

int main() {
  Solution sol;
  vector<int> num = {103, 100, 3, 200, 105, 104, 1, 4, 2, 5, 101, 102};
  cout << sol.longestConsecutive(num) << endl;
  
  return 0;
}