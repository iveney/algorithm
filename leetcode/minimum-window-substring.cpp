#include "leetcode.h"

class Solution {
public:
  string minWindow(string S, string T) {
    if (S.size() == 0 || T.size() == 0) return string("");

    int hasFound[256] = {0};
    int toFound[256] = {0};
    // count the number of requried chars in T
    for (char c : T) {
      ++toFound[c];
    }

    int count = 0;
    int minLen = numeric_limits<int>::max();
    int minBegin = -1;
    for (int begin = 0, end = 0; end < S.size(); ++end) {
      // advance end pointer and see if found a valid window
      if (toFound[S[end]] == 0) {
        continue;
      }

      // only count when the requirement is not met
      if (hasFound[S[end]] < toFound[S[end]]) {
        ++count;
      }
      ++hasFound[S[end]];

      // found a valid window, advance begin pointer
      if (count >= T.size()) {
        while (toFound[S[begin]] == 0 ||
               hasFound[S[begin]] > toFound[S[begin]]) {
          if (toFound[S[begin]] > 0) {
            --hasFound[S[begin]];
          }
          ++begin;
        }

        // new window
        int newLen = end - begin + 1;
        if (newLen < minLen) {
          minLen = newLen;
          minBegin = begin;
          // cout << "Find new window: " << begin << ", " << end << '\n';
        }
      }
    }

    string result;
    if (count >= T.size()) {
      result = S.substr(minBegin, minLen);
    }
    return result;
  }
};

int main() {
  // string S("acbbaca");
  // string T("aba");
  string S("ADOBECODEBANC");
  string T("BAC");
  Solution sol;
  cout << sol.minWindow(S, T) << '\n';
  
  return 0;
}