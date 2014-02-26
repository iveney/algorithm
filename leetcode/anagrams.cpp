// interesting problem, can practice again
#include "leetcode.h"

class Solution {
public:
  vector<string> anagrams(vector<string> &strs) {
    vector<string> result;
    unordered_map<string, int> count;
    vector<string> anagram;

    for (string s : strs) {
      string sorted = s;
      sort(sorted.begin(), sorted.end());
      anagram.push_back(sorted);
      count[sorted]++;
    }

    for (int i = 0; i < strs.size(); ++i) {
      string sorted = anagram[i];
      if (count[sorted] > 1) {
        result.push_back(strs[i]);
      }
    }
    return result;

  }
};

int main() {
  Solution sol;
  vector<string> strs = {"dog","cat","god","tac"};
  vector<string> anagrams = sol.anagrams(strs);
  copy(anagrams.begin(), anagrams.end(), 
    ostream_iterator<decltype(anagrams)::value_type>(cout, " "));
  cout << '\n';
  
  return 0;
}