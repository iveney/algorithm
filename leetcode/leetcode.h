#ifndef _LEETCODE_H_
#define _LEETCODE_H_

// headers for TreeNode, ListNode, and utility functions

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
// tree related
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// struct TreeLinkNode {
//   int val;
//   TreeLinkNode *left, *right, *next;
//   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {} 
// };

struct TreeLinkNode : public TreeNode {
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : TreeNode(x), left(NULL), right(NULL), next(NULL) {} 
};

// return an identical tree from root, next is untouched (NULL)
TreeLinkNode *fromTreeNode(TreeNode *root) {
  if (root == NULL) return NULL;

  TreeLinkNode *node = new TreeLinkNode(root->val);
  node->left = fromTreeNode(root->left);
  node->right = fromTreeNode(root->right);
  return node;
}

ostream & operator << (ostream &os, TreeLinkNode *node) {
  if (node == NULL)
    os << "#";
  else
    os << node->val;
  return os;
}

void printTreeLinkNode(TreeLinkNode *root) {
  if (root == NULL) return;
  cout << root->val << ":";
  cout << " L = " << root->left;
  cout << " R = " << root->right;
  cout << " N = " << root->next;
  cout << '\n';
  printTreeLinkNode(root->left);
  printTreeLinkNode(root->right);
}

void preorder(TreeNode *root, function<void(TreeNode*)> func) {
  if (root == NULL)
    return;

  func(root);
  preorder(root->left, func);
  preorder(root->right, func);
}

void inorder(TreeNode *root, function<void(TreeNode*)> func) {
  if (root == NULL)
    return;

  inorder(root->left, func);
  func(root);
  inorder(root->right, func);
}

void postorder(TreeNode *root, function<void(TreeNode*)> func) {
  if (root == NULL)
    return;

  postorder(root->left, func);
  postorder(root->right, func);
  func(root);
}

void cout_tree_node(TreeNode *node) {
  if (node == NULL) return;
  cout << node->val << " ";
}

void preorder_cout(TreeNode *root) {
  preorder(root, cout_tree_node);
  cout << endl;
}

void inorder_cout(TreeNode *root) {
  inorder(root, cout_tree_node);
  cout << endl;
}

void postorder_cout(TreeNode *root) {
  postorder(root, cout_tree_node);
  cout << endl;
}

void level_order_cout(TreeNode *root) {
  queue<TreeNode *> curr, next;
  queue<TreeNode *> *p_curr = &curr, *p_next = &next;
  p_curr->push(root);

  while (!p_curr->empty()) {
    TreeNode *p = p_curr->front();
    p_curr->pop();

    if (p == NULL)
      cout << "# ";
    else {
      cout << p->val << ' ';
      p_next->push(p->left);
      p_next->push(p->right);
    }

    if (p_curr->empty()) {
      cout << '\n';

      queue<TreeNode *> *tmp = p_curr;
      p_curr = p_next;
      p_next = tmp;
    }
  } // while
}

void serialize_tree_recursive(FILE* f, TreeNode *root) {
  if (root == NULL) {
    fprintf(f, "# ");
  } else {
    fprintf(f, "%d ", root->val);
    serialize_tree_recursive(f, root->left);
    serialize_tree_recursive(f, root->right);
  }
}

// serialize tree to file using pre-order
void serialize_tree(const char* filename, TreeNode *root) {
  FILE* f = fopen(filename, "w");
  if ( f == NULL ) {
    fprintf(stderr, "Open file %s failed.\n", filename);
    return;
  }

  serialize_tree_recursive(f, root);

  fclose(f);
}

// pre order deserialize
void deserialize_tree_recursive(istream& stream, TreeNode *&node) {
  string token;
  if ( !(stream >> token) )
    return;

  // sentinel
  if (token == "#") {
    node = NULL;
    return;
  }

  int val = stoi(token);
  node = new TreeNode(val);
  deserialize_tree_recursive(stream, node->left);
  deserialize_tree_recursive(stream, node->right);
}

TreeNode *deserialize_tree(const char* filename) {
  ifstream ifs(filename);
  if ( !ifs ) {
    cerr << "Open file " << filename << "failed.\n";
    return NULL;
  }

  TreeNode *root = NULL;
  deserialize_tree_recursive(ifs, root);
  ifs.close();

  return root;
}

// deserialize string from a C++ string
TreeNode *deserialize_tree(const string& serialize_str) {
  istringstream ss(serialize_str);
  TreeNode *root = NULL;
  deserialize_tree_recursive(ss, root);

  return root;
}

///////////////////////////////////////////////////////////////////////////////
// linked list related

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(NULL) {}
};

void print_list(ListNode *head) {
  while(head != NULL) {
    cout << head->val << ' ';
    head = head->next;
  }
  cout << '\n';
}

ListNode *list_from_array(int* arr, int n) {
  if (n == 0) return NULL;
  ListNode *head = new ListNode(arr[0]);
  ListNode *p = head;
  for (int i = 1; i < n; ++i) {
    p->next = new ListNode(arr[i]);
    p = p->next;
  }
  return head;
}

ListNode *list_from_array(vector<int> v) {
  return list_from_array(v.data(), v.size());
}

///////////////////////////////////////////////////////////////////////////////
// Undirected graph
struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

// deserialize a graph
// assume the serialization is correct
UndirectedGraphNode *deserialize_graph(istream& in) {
  unordered_map<int, UndirectedGraphNode *> map;
  UndirectedGraphNode *current_node = NULL;
  UndirectedGraphNode *ret = NULL;

  string token;
  while ( getline(in, token,'#') ) {
    current_node = NULL;
    istringstream line(token);
    string str_label;
    while ( getline(line, str_label, ',') ) {
      int label = stoi(str_label);
      if (current_node == NULL) {
        // this is a new node
        current_node = map[label];
        if (current_node == NULL)
          map[label] = current_node = new UndirectedGraphNode(label);

        if (ret == NULL) ret = current_node;
      } else {
        // this is a neighbor node
        UndirectedGraphNode *nbr = map[label];
        if ( nbr == NULL )
          map[label] = nbr = new UndirectedGraphNode(label);

        current_node->neighbors.push_back(nbr);
      }
    } // while
  } // while

  return ret;
}

UndirectedGraphNode *deserialize_graph(const string &str) {
  istringstream ss(str);
  return deserialize_graph(ss);
}

void serialize_graph(ostream& os, UndirectedGraphNode *node) {
  if (node == NULL) return;
  
  std::queue<UndirectedGraphNode *> myqueue;
  std::unordered_set<int> visited;
  myqueue.push(node);

  while ( !myqueue.empty() ) {
    UndirectedGraphNode *p = myqueue.front();
    myqueue.pop();

    // already visited this node
    if ( visited.find(p->label) != visited.end() )
      continue;

    visited.insert(p->label);
    os << p->label;
    for (auto nbr : p->neighbors) {
      os << ',' << nbr->label;
      if ( visited.find(nbr->label) == visited.end() )
        myqueue.push(nbr);
    }
    if (!myqueue.empty())
      os << '#';
  }
  os << endl;
}

// Dump the binary tree to graphviz format
void dump_tree_graphviz_recursive(TreeNode* root) {
  if (root == NULL) return;

  if (root->left) {
    cout << root->val << " -> " << root->left->val << ";\n";
  }

  if (root->right) {
    cout << root->val << " -> " << root->right->val << ";\n";
  }
}

void dump_tree_graphviz(const string &name, TreeNode* root) {
  cout << "digraph " << name << " {\n";
  preorder(root, dump_tree_graphviz_recursive);
  cout << "}\n";
}

#endif