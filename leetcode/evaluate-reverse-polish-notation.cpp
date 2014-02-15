#include <stack>
#include "leetcode.h"

class Solution {
  void pop_op(stack<string> &st, string &op1, string &op2) {
    op2 = st.top();
    st.pop();
    op1 = st.top();
    st.pop();
  }

public:
  int evalRPN(vector<string> &tokens) {
    stack<string> st;
    string op1, op2;
    for (string s: tokens) {
      if (s == "+") {
        pop_op(st, op1, op2);
        int ans = stoi(op1) + stoi(op2);
        st.push(to_string(ans));
      } else if (s == "-") {
        pop_op(st, op1, op2);
        int ans = stoi(op1) - stoi(op2);
        st.push(to_string(ans));
      } else if (s == "*") {
        pop_op(st, op1, op2);
        int ans = stoi(op1) * stoi(op2);
        st.push(to_string(ans));
      } else if (s == "/") {
        pop_op(st, op1, op2);
        int ans = stoi(op1) / stoi(op2);
        st.push(to_string(ans)); 
      } else {
        st.push(s);
      }
    } // for
    return stoi(st.top());
  }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  string t1[] = {"2", "1", "+", "3", "*"};
  string t2[] = {"4", "13", "5", "/", "+"};
  string t3[] = {"18"};
  vector<string> s1(t1, t1 + sizeof(t1) / sizeof(string));
  vector<string> s2(t2, t2 + sizeof(t2) / sizeof(string));
  vector<string> s3(t3, t3 + sizeof(t3) / sizeof(string));

  cout << sol.evalRPN(s1) << endl;
  cout << sol.evalRPN(s2) << endl;
  cout << sol.evalRPN(s3) << endl;
  return 0;
}