#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<char, string> mapping;
unordered_set<string> exist;

int wordpattern(string pattern, string input) {
  if (pattern.empty() && input.empty()) return 1;
  if (pattern.empty() || input.empty()) return 0;

  string &m = mapping[pattern[0]];
  string remain = pattern.substr(1, pattern.size());
  if (!m.empty()) {
    // mapping already exist
    int ilen = input.size();
    if (input.substr(0, m.size()) == m && ilen >= m.size()) {
      return wordpattern(remain, input.substr(m.size(), ilen - m.size()));
    } else {
      return 0;
    }
  } else {
    // no match, try to match
    for (int i = 1; i <= input.size(); ++i) {
      if (exist.find(input.substr(0, i)) != exist.end()) {
        continue;
      }
      m = input.substr(0, i);
      exist.insert(m);
      if (wordpattern(remain, input.substr(i, input.size()))) {
        return 1;
      }
      exist.erase(m);
      m = "";
    }
  }
  return 0;
}


int main() {
  ofstream fout(getenv("OUTPUT_PATH"));
  int res;
  string _pattern;
  getline(cin, _pattern);

  string _input;
  getline(cin, _input);

  res = wordpattern(_pattern, _input);
  fout << res << endl;
  // if (res) {
  //   fout << "Mappings: \n";
  //   for (auto it : mapping) {
  //     fout << it.first << " -> " << it.second << "\n";
  //   }
  //   fout << "Exists: " << exist.size() << "\n";
  //   for (auto it : exist) {
  //     fout << it << "\n";
  //   }
  // }

  fout.close();
  return 0;
}