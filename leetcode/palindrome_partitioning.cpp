#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
using std::string;
using std::cout;
using std::endl;

// http://leetcode.com/onlinejudge#question_131
// Idea:
// recursively divide string into prefix + postfix
// if prefix is palindrome, result = prefix + {partition postfix}

typedef vector<string> VecS;
typedef vector<VecS> VecVecS;

void output(const VecVecS& v) {
  cout << "[\n";
  for_each(v.begin(), v.end(), [&](const VecS& w){
    cout << "    [";
    for_each(w.begin(), w.end(), [&](const string& s){
      cout << "\"" << s << "\" ";
    });
    cout << "]\n";
  });
  cout << "]\n";
}


class Solution {
public:
  typedef vector<string> VecS;
  typedef vector<VecS> VecVecS;

  VecVecS partition(string s) {
    vector< vector<string> > result;
    if (s == "")
      return result;

    for (int i = 1; i <= s.length(); ++i) {
      string prefix = s.substr(0, i);
      // cout << "Prefix = " << prefix << endl;
      if ( !isPalindrome(prefix) ) 
        continue;
      if (i == s.length()) {
        result.push_back(VecS(1, prefix));
        return result;
      }
      string post = s.substr(i);
      // cout << "Post = " << post << endl;
      VecVecS ret = partition(post);
      for_each(ret.begin(), ret.end(), [&](const VecS& vecs) {
        VecS parts;
        parts.push_back(prefix);
        parts.insert(parts.end(), vecs.begin(), vecs.end());
        result.push_back(parts);
      });
    }
    return result;
  }

  bool isPalindrome(const string& s) {
    int half = s.length() / 2;
    for (int i = 0; i < half; ++i) {
      if ( s[i] != s[s.length() - i - 1] )
        return false;
    }
    // cout << s << " is palindrome\n";
    return true;
  }

};


int main() {
  Solution solution;
  string s = "aab";
  VecVecS v = solution.partition(s);
  output(v);
  return 0;
}
