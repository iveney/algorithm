#include <vector>
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

/*
 * Complete the function below.
 */
string validateString(string value) {
  stack<char> st;
  for (auto c : value) {
    if (c == '(' ||
        c == '[' ||
        c == '{') {
      st.push(c);
    } else {
      if (st.empty()) {
        return "NO";
      }
      char t = st.top();
      st.pop();
      if ((c == ')' && t != '(') ||
          (c == ']' && t != '[') ||
          (c == '}' && t != '{')) {
        return "NO";
      }
    }
  }
  
  return st.empty()? "YES" : "NO";
}

int main() {
  vector<string> values{
    // "",
    // "{",
    // "}",
    // "{(})",
    // "[[[((()))]]]{}",
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
  for (auto &s : values) {
    cout << validateString(s) << endl;
  }
  return 0;
}

