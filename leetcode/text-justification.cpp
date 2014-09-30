// https://oj.leetcode.com/problems/text-justification/

#include "leetcode.h"

class Solution {
public:
  vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> result;
    int n = words.size();
    int i = 0, j = 0;
    while (i < n) {
      // try padding next word
      int len = 0;
      int wordlen = 0;
      while (j < n) {
        int newlen = len + words[j].size();
        if (i != j) {
          // space between words
          ++newlen;
        }
        if (newlen <= L) {
          wordlen += words[j].size();
          len = newlen;
          ++j;
        } else {
          break;
        }
      }
      
      // either j == n or words[j] cannot fit in
      
      // count the spaces to fit in
      int nspace = L - wordlen;
      int nwords = j - i;
      int nslots = nwords - 1;
      int spsize = nslots? (nspace / nslots) : nspace;
      int nextra = nslots? (nspace % nslots) : 0;
      if (j == n) {
        // special case for last line
        spsize = 1;
        nextra = 0;
      }
      string space(spsize, ' ');
      string line;
      
      // pack into a line
      for (int k = 0; k < nwords; ++k) {
        line += words[i+k];
        if (nextra > 0) {
          // extra space
          string extraspace = string(spsize + 1, ' ');
          line += extraspace;
          --nextra;
        } else if (nwords == 1 || (k == nwords - 1 && j == n)) {
          // a line that contains only one word or last line is left-justified
          line += string(L - line.size(), ' ');
        } else if (k < nwords - 1) {
            // don't pack space for last word
          line += space;
        }
      }
      
      result.push_back(line);
      i = j;
    } // while (i < n)
    
    return result;
  }
};

int main() {
  // vector<string> words{"This", "is", "an", "example", "of", "text", "justification."};
  // vector<string> words{"long", "justification."};
  // vector<string> words{""};
  // vector<string> words{"What","must","be","shall","be."};
  vector<string> words{"Don't","go","around","saying","the","world","owes","you","a","living;","the","world","owes","you","nothing;","it","was","here","first."};
  int L = 30;
  Solution sol;
  auto result = sol.fullJustify(words, L);
  copy(result.begin(), result.end(), 
      ostream_iterator<decltype(result)::value_type>(cout, "|\n"));  
  return 0;
}