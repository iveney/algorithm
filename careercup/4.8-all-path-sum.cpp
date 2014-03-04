#include "../leetcode/leetcode.h"

class Solution {
  vector<vector<int> > result;
public:
  vector<vector<int> > all_path_sum(TreeNode *root, int sum) {
    vector<int> path;
    all_path_sum(root, path, sum);
    return result;
  }

  void all_path_sum(TreeNode *root, 
    vector<int> &path, int sum) {
    if (root == NULL) return;

    path.push_back(root->val);
    int tmp = sum;
    for (int i = path.size() - 1; i >= 0; --i) {
      tmp -= path[i];
      if (tmp == 0) {
        result.push_back(vector<int>(path.begin()+i, path.end()));
      }
    }
    vector<int> c1(path), c2(path);
    all_path_sum(root->left, c1, sum);
    all_path_sum(root->right, c2, sum);
  }
};


int main(int argc, char const *argv[]) {
  string tree = "2 3 6 -3 # # -1 # # -4 2 # # 3 1 -5 # # 2 # # 4 # # 4 -3 7 -3 # # -2 # # 2 # # 2 5 # # 1 # #";
  TreeNode *root = deserialize_tree(tree);

  Solution sol;
  auto result = sol.all_path_sum(root, 5);
  for (auto v : result) {
    copy(v.begin(), v.end(), 
      ostream_iterator<decltype(v)::value_type>(cout, " ")); 
    cout << '\n';
  }

  return 0;
}