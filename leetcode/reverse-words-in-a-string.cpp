#include <sstream>
#include "leetcode.h"

class Solution {
public:
  void reverseWords(string &s) {
    stringstream ss(s);
    string word;
    stack<string> st;
    while (ss >> word) {
      st.push(word);
    }

    s.clear();
    while (!st.empty()) {
      s += st.top() + " ";
      st.pop();
    }
    int n = s.size();
    if (n > 0)
      s.resize(n-1);
  }

};

int main() {
  vector<string> ss {
    "the sky is blue",
    "    the sky is blue    ",
  };

  Solution sol;
  for (auto s : ss) {
    sol.reverseWords(s);
    cout << s << endl;
  }
  
  return 0;
}