#include <iostream>
#include "BKtree.h"
#include "levenshtein_distance.h"

void BKTreeNode::insert(const string &w) {
  size_t dist = levenshtein_distance(word, w);
  if (dist == 0) return;

  auto &p = children[dist];
  if (p != nullptr) {
    p->insert(w);
  } else {
    p = new BKTreeNode(w);
  }
}

BKTreeNode::~BKTreeNode() {
  for (auto it : children) {
    delete it.second;
  }
}

BKTree::BKTree(istream &is) : root(nullptr) {
  string word;
  while (is >> word) {
    if (root == nullptr) {
      root = new BKTreeNode(word);
    } else {
      root->insert(word);
    }
  }
}

BKTree::~BKTree() {
  if (root != nullptr) {
    delete root;
  }
}

void BKTreeNode::search(const string &w, int tol, vector<string> &result) {
  int dist = levenshtein_distance(this->word, w);
  if (dist <= tol) {
    result.push_back(this->word);
  }

  int l = std::max(dist - tol, 0), h = dist + tol;
  for (auto it : children) {
    if ( l <= it.first && it.first <= h ) {
      it.second->search(w, tol, result);
    }
  }
}

vector<string> BKTree::search(const string &word, int tol) {
  vector<string> result;
  if (root) {
    root->search(word, tol, result);
  }
  return result;
}
