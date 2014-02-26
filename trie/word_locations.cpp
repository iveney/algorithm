// Find the location of words in a document
// e.g., for
//
// hi
// hello
// hi
//
// return 
// {
//   hi: [1, 3]
//   hello: [2]
// }

// inspired from: http://www.ardendertat.com/2011/12/20/programming-interview-questions-23-find-word-positions-in-text/

#include <string>
#include <sstream>
#include <list>
#include <iostream>
using namespace std;

// assume case-insensitive and only contains a-z
struct TrieNode {
  TrieNode *child[26] = {NULL};
  list<int> pos;
};

void insert(TrieNode *root, const string &word, int pos) {
  if (root == NULL) return;

  TrieNode *p = root;
  for (char c: word) {
    int k = tolower(c) - 'a';
    if (p->child[k] == NULL) {
      p->child[k] = new TrieNode;
    }
    p = p->child[k];
  }
  p->pos.push_back(pos);
}

void print_positions(TrieNode *root, const string &prefix) {
  if (root == NULL) return;

  if ( !root->pos.empty() ) {
    cout << prefix << ": ";
    copy(root->pos.begin(), root->pos.end(), 
      ostream_iterator<decltype(root->pos)::value_type>(cout, " "));
    cout << '\n';
  }

  int nchild = sizeof(root->child) / sizeof(TrieNode*);
  for (int i = 0; i < nchild; ++i) {
    char c = i + 'a';
    print_positions(root->child[i], prefix + c);
  }
}

int main(int argc, char const *argv[]) {
  string words = "us use uses used user users using useful username user utah";
  stringstream ss(words);

  string word;
  TrieNode *root = new TrieNode;
  int line = 0;
  while (getline(ss, word, ' ')) {
    insert(root, word, line);
    ++line;
  }

  // print out all the positions
  print_positions(root, "");

  return 0;
}
