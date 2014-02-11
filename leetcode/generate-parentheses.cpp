// interesting problem, practice again
#include <string>
#include "leetcode.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
      vector<string> result;
      string prefix("");
      gen(result, prefix, 0, n);
      return result;
    }

    void gen(vector<string> &result, string prefix, int l, int k) {
      if (l == 0 && k == 0) {
        result.push_back(prefix);
        return;
      }

      // insert one left parenthesis
      if (k > 0) {
        gen(result, prefix + "(", l+1, k-1);
      }

      // close one left parenthesis
      if (l > 0) {
        gen(result, prefix + ")", l-1, k);
      }
    }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  auto result = sol.generateParenthesis(4);
  for (auto str : result) {
    cout << str << '\n';
  }
  return 0;
}