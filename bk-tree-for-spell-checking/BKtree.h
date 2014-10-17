#ifndef _BKTREE_H_
#define _BKTREE_H_

#include <fstream>
#include <string>
// #include <unordered_map>
#include <map>
#include <vector>
using std::istream;
using std::string;
// using std::unordered_map;
using std::map;
using std::vector;

#include <boost/serialization/map.hpp>

class BKTreeNode {
public:
  BKTreeNode(const string &w = "") : word(w) {}
  void insert(const string &w);
  void search(const string &w, int dist, vector<string> &result);
  ~BKTreeNode();

private:
  string word;
  // unordered_map<size_t, BKTreeNode *> children;
  map<size_t, BKTreeNode *> children;

  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version)
  {
      ar & word;
      ar & children;
  }
};

class BKTree {
public:
  // Construct a BKTree from dictionary
  BKTree(istream& is);
  BKTree() : root(nullptr) {};
  ~BKTree();

  vector<string> search(const string &word, int tol);

private:
  BKTreeNode *root;
  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version)
  {
      ar & root;
  }
};

#endif