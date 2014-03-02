// http://leetcode.com/2011/05/longest-substring-without-repeating-characters.html
#include "leetcode.h"

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if (n <= 1) return n;

    unordered_map<char, int> map;
    map[s[0]] = 0;
    int max = 1;
    int len = 1;
    vector<int> start(n); // records starting point of max substring ended at i
    start[0] = 0;
    for (int i = 1; i < n; ++i) {
      char c = s[i];

      if (map.find(c) != map.end()) {
        // found repeating char
        int cid = map[c];
        start[i] = cid + 1;
        for(int j = start[i-1]; j < cid; ++j) {
          map.erase(s[j]);
          len--;
        }
        map[c] = i;
      } else {
        start[i] = start[i-1];
        map[c] = i;
        ++len;
        max = std::max(max, i - start[i] + 1);
      }
    } // for

    return max;
  }
};

int main() {
  vector<string> str {
    "abcabcbb",
    "bbbb",
    "abcabdeaghi"
  };
  Solution sol;
  for (auto &s : str) {
    printf("%d\n", sol.lengthOfLongestSubstring(s));
  }
  
  return 0;
}