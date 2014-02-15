#include <stack>
#include  "leetcode.h"

class Solution {
public:
    bool isValid(string s) {
      stack<char> st;
      for (char c : s) {
        if (c == '(' || c == '[' || c == '{')
          st.push(c);
        else {
          if (st.empty())
            return false;
          char l = st.top();
          if ((l == '(' && c == ')') ||
              (l == '[' && c == ']') ||
              (l == '{' && c == '}'))
            st.pop();
          else
            return false;
        }
      } // for
      if (!st.empty())
        return false;

      return true;
    }
};

int main(int argc, char const *argv[])
{
  string s[] = {
    "()",
    "()[]{}",
    "(]",
    "([)]",
    "",
    "(",
    "]",
    "{}{}{{{{[[[((()))]]]}}}}",
    "{}{}{{{{[[[(((])))]]]}}}}",
  };
  Solution sol;
  for (string str : s) {
    cout << str << ": " << sol.isValid(str) << endl;
  }
  return 0;
}