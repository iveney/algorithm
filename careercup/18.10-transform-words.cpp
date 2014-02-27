#include <list>
#include <queue>
#include "../leetcode/leetcode.h"

struct Item {
  Item(string s, Item *par = NULL) : str(s), parent(par) {}

  Item *parent;
  string str;
};

bool next_to(const string &s1, const string &s2) {
  if (s1.size() != s2.size()) return false;
  int count = 0;
  for (int i = 0; i < s1.size(); ++i) {
    if (s1[i] != s2[i]) {
      ++count;
      if (count > 1)
        return false;
    }
  }

  return (count == 1);
}

list<string> transform_words(const string &begin, const string &end,
                             const vector<string> &dict) {
  list<string> words;
  vector<bool> visited(dict.size(), false);
  queue<Item*> qu;
  qu.push(new Item(begin, NULL)); 
  while (!qu.empty()) {
    Item* w = qu.front();
    qu.pop();

    // propagate neighbors
    for (int i = 0; i < dict.size(); ++i) {
      if (visited[i])
        continue;
      if ( next_to(w->str, dict[i]) ) {
        if (dict[i] == end) {
          // back track
          words.push_front(end);
          while (w != NULL) {
            words.push_front(w->str);
            w = w->parent;
          }
          return words;
        }

        qu.push(new Item(dict[i], w));
        visited[i] = true;
      }
    } // for
  } // while 

  return words;
}

int main() {
  vector<string> dict = {
    "DAMC",
    "DAMM",
    "DAPM",
    "DAMP",
    "LIKE",
    "LIMP",
    "LIME",
    "LAMP",
    "PLAM",
    "AMPL",
    "AAPL",
    "PLAA",
    "LINE",
    "CINE",
  };

  list<string> words = transform_words("DAMP", "CINE", dict);
  copy(words.begin(), words.end(), 
    ostream_iterator<decltype(words)::value_type>(cout, " "));
  cout << '\n';

  return 0;
}