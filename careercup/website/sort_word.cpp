// http://www.careercup.com/question?id=22524667
// http://www.careercup.com/question?id=15555705

#include <unordered_map>
#include <iostream>
using namespace std;

// sort the words according to a dictionary
// assume all char in word appears in dict
string sort_word(string &word, string &dict) {
  unordered_map<char, int> map;
  int count = 0;
  for (auto c : dict) {
    map[c] = count++;
  }

  string sorted(word);
  sort(sorted.begin(), sorted.end(), [& map](char a, char b) {
    return map[a] < map[b];
  });

  return sorted;
}

int main(int argc, char const *argv[])
{
  string word = "SHEEP";
  string dict = "PHES";
  string sorted = sort_word(word, dict);
  cout << sorted << endl;
  return 0;
}