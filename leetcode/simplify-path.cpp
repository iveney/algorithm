#include "leetcode.h"

struct DoubleLinkList {
  DoubleLinkList(string nd, DoubleLinkList* p = NULL) :
    next(NULL), prev(p), node(nd) {}
  DoubleLinkList* next, *prev;
  string node;
};

class Solution {
public:
  string simplifyPath(string path) {
    // simple corner case
    if (path == "" || path == "/")
      return path;

    // this should not happen assuming the input is correct
    if (path[0] != '/') {
      return path;
    }

    // create the root node
    DoubleLinkList* root = new DoubleLinkList("/", NULL);
    DoubleLinkList* curr = root;
    int i = 1;
    while(i < path.size()) {
      // remove excess '/'
      while (path[i] == '/') {
        ++i;
      }

      if (i >= path.size()) {
        break;
      }

      // tokenize the path
      int j = i + 1;
      while (j < path.size() && path[j] != '/') {
        ++j;
      }

      // i..j-1 is the new token
        string str = path.substr(i, j - i);
        if (str == ".") {
          // redundant current dir
        } else if (str == "..") {
          // go one level up, note that stay at root if no parent
          if (curr->prev != NULL) {
            curr = curr->prev;
            curr->next = NULL;
          }
        } else {
          // finally normal case, create new level
          curr->next = new DoubleLinkList(str, curr);
          curr = curr->next;
        }
      i = j+1;
    }
    // trace from root to output the canonical path
    string norm = "/";
    curr = root->next;
    while (curr != NULL) {
      if (curr->prev != root) {
        norm += "/";
      }
      norm += curr->node;
      curr = curr->next;
    }
    return norm;
  }
};

int main() {
  vector<string> paths = {
    // "/",
    // "//",
    // "///",
    // "/..",
    // "/../",
    // "/./",
    // "/././",
    // "/abc/../",
    // "/abc/..",
    // "/abc/./../",
    "/a/b/c/",    // /a/b/c
    "/a/b/c/..",  // /a/b
    "/abc/def/./ghi/./../..////",  // /abc/
    "/abc/def/./ghi/./../..////../../..///.",  // /
    "/home//foo/",
  };
  Solution sol;
  for(const string& path : paths) {
    cout << sol.simplifyPath(path) << endl;
  }
  
  return 0;
}