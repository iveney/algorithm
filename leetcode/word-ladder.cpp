#include "leetcode.h"

class Solution {
public:
  bool isNbr(const string &a, const string &b) const {
    int count = 0;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] != b[i]) {
        ++count;
      }
      if (count > 1) return false;
    }
    return count == 1;
  }

  int ladderLength(string start, string end, unordered_set<string> &dict) {
    queue<pair<string, int> > q;
    q.push(make_pair(start, 1));
    while (!q.empty()) {
      string word;
      int len;
      tie(word, len) = q.front();
      q.pop();
      if (isNbr(word, end)) {
        return len + 1;
      }

      auto it = dict.begin();
      while (it != dict.end()) {
        auto it2 = it;
        ++it;
        if (isNbr(*it2, word)) {
          q.push(make_pair(*it2, len + 1));
          dict.erase(it2);
        }
      }
    }// while

    return 0;
  }
};

int main() {
  // string start = "hit";
  // string end = "cog";
  // unordered_set<string> dict{"hot","dot","dog","lot","log"};
  string start = "hot";
  string end = "dog";
  unordered_set<string> dict{"hot","cog","dog","tot","hog","hop","pot","dot"};
  Solution sol;
  cout << sol.ladderLength(start, end, dict) << '\n';
  
  return 0;
}