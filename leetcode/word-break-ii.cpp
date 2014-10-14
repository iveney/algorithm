#include "leetcode.h"

class Solution {
public:
  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    int n = s.size();
    vector<bool> canBreak(n + 1, false);
    canBreak[0] = true;
    words.resize(n+1);
    for (int i = 0; i < n; ++i) {
      if (!canBreak[i]) {
        continue;
      }

      for (auto &word : dict) {
        int j = word.size();
        if (i + j <= n && word == s.substr(i, j)) {
          words[i+j].push_back(i);
          canBreak[i+j] = true;
        }
      } // for
    } // for i

    string dummy;
    backtrack(s, dict, dummy, n);
    return result;
  }

  // dfs to backtrack all the paths
  void backtrack(const string &s, const unordered_set<string> &dict,
                 string &path, int j) {
    if (j == 0) {
      result.push_back(path);
      return;
    }

    for (int i : words[j]) {
      string npath = s.substr(i, j - i);
      if (!path.empty()) {
        npath += " " + path;
      }
      backtrack(s, dict, npath, i);
    }
  }
  
  // For the following case:
  //
  // string s = "catsanddog";
  // unordered_set<string> dict = {"cat", "cats", "and", "sand", "dog"};

  // the words array looks like:
  // 
  // 0 -- 3 -- 7 -- 10
  //   \_ 4 __/
  //
  // so there are two paths

  vector<vector<int> > words;  // tracks the prior breaking position
  vector<string> result;
};

int main() {
  string s = "catsanddog";
  unordered_set<string> dict = {"cat", "cats", "and", "sand", "dog"};

  // the words array looks like:
  // 0 -- 3 -- 7 -- 10
  //   \_ 4 __/

  // string s = "leetcodecodeleet";
  // unordered_set<string> dict = {"leet", "code", "feet", "cdma", "lee", "vis"};

  // string s = "";
  // unordered_set<string> dict = {"leet", "code", "feet", "cdma", "lee", "vis"};

  Solution sol;
  auto result = sol.wordBreak(s, dict);
  copy(result.begin(), result.end(), 
    ostream_iterator<decltype(result)::value_type>(cout, "\n"));
  
  return 0;
}