#ifndef _BKTREE_H_
#define _BKTREE_H_

#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
using std::istream;
using std::string;
using std::unordered_map;
using std::vector;

class BKTreeNode {
public:
  BKTreeNode(const string &w) : word(w) {}
  void insert(const string &w);
  void search(const string &w, int dist, vector<string> &result);
  ~BKTreeNode();

private:
  string word;
  unordered_map<size_t, BKTreeNode *> children;
};

class BKTree {
public:
  // Construct a BKTree from dictionary
  BKTree(istream& is);
  ~BKTree();

  vector<string> search(const string &word, int tol);

private:
  BKTreeNode *root;
};

#endif