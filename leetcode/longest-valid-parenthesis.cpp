// interesting DP solution
#include "leetcode.h"

// idea is to maintain the current longest valid parenthesis ending at i (exclusive)
// also keep track of the position of all previous '('
// whenever we encounter a ')', we see if the stack is empty
//
// - if stack empty, the current valid parenthesis breaks and we reset the current length
// - if not, we know that the new length is the length between the current len + 2, and if the last '(' is at l
// and if l-1 is also a valid string, we update the total length to be D[i-1] + 2 + D[l-1];
class Solution {
public:
    int longestValidParentheses(string s) {
      int n = s.size();
      if (n <= 1) return 0;
      vector<int> D(n + 1);   // max len in range 0..i-1, ending at s[i-1]
      D[0] = 0;
      vector<int> left;
      int len = 0;
      for (int i = 1; i <= n; ++i) {
          if (s[i-1] == ')') {
              if (left.size() > 0) {
                  int l = left.back();
                  left.pop_back();
                  D[i] = D[i-1] + D[l-1] + 2;
              } else {
                  // valid string breaks
                  D[i] = 0;
                  left.clear();
              }
          } else {
              // '('
              D[i] = 0;
              left.push_back(i);
          }
          if (D[i] > len) {
              len = D[i];
          }
      }
      
      return len;
  }
};

int main(int argc, char const *argv[]) {
  vector<string> str {
    "()",
    ")(",
    ")()",
    "()()",
    "()((()()))",
    ")",
    "(",
    "",
    "()())()(())",
  };
  Solution sol;
  for (auto &s : str) {
    cout << sol.longestValidParentheses(s) << "\n";
  }
  return 0;
}