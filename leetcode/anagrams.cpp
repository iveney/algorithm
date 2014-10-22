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
// idea is to generate a canonical string by counting all characters: O(l)
// set up a pair to bookmark the first appearance of this canonical string
// second in the pair denotes whether this has been added
// when we see another string that has a canonical string appeared before
// we add the string and the previous string if it has not been added
class Solution2 {
public:
  vector<string> anagrams(vector<string> &strs) {
    vector<string> result;
    unordered_map<string, pair<int, bool> > bags;
    for (int i = 0; i < strs.size(); ++i) { 
      string canonical = getSortedStr(strs[i]);
      auto it = bags.find(canonical);
      if ( it != bags.end()) {
        result.push_back(strs[i]);
        auto &p = it->second;
        if (p.second == false) {
          p.second = true;
          result.push_back(strs[p.first]);
        }
      } else {
        bags[canonical] = make_pair(i, false);
      }
    }

    return result;
  }

  string getSortedStr(const string& s) {
    int count[26] = {0};
    for (char c : s) {
      ++count[c-'a'];
    }

    string result;
    for (int i = 0; i < 26; ++i) {
      result += string(count[i], i + 'a');
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