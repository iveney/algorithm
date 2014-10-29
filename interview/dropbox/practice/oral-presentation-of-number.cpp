#include <iostream>
#include <vector>
#include <string>
using namespace std;

string oral_presentation(string num) {
  string s;
  int n = num.size();
  if (n == 0) return s;
  int i = 0;
  while (i < n) {
    char prev = num[i];
    int count = 1;
    while (i+1 < n && num[i+1] == prev) {
      ++i;
      ++count;
    }
    s += to_string(count) + prev;
    ++i;
  }
  return s;
}

// Given output from oral_presentation, return the possible inputs
// e.g., 1211 can be:
// - 121 1
// - 1 2/1 1
class PossibleInput {
public:
  vector<string> ans;
  void dfs(string &prefix, string oral, int i) {
    if (i >= oral.size()) {
      ans.push_back(prefix);
    }
    // i..j-1, j, where oral[i..j-1] is the length, oral[j] is the num
    // j-1 >= i (at least two digits)
    int n = oral.length();
    for (int j = i+1; j < n; ++j) {
      string len = oral.substr(i, j-i);
      string new_prefix = prefix;
      if (!new_prefix.empty()) new_prefix += ", ";
      new_prefix += len + " " + oral[j];
      dfs(new_prefix, oral, j+1);
    }
  }

  vector<string> find(string oral) {
    string prefix;
    dfs(prefix, oral, 0);
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  vector<string> nums = {
    "1",
    "11",
    "12",
    "21",
    "1211",
  };
  for (auto num : nums) {
    string oral = oral_presentation(num);
    cout << num << " Oral: " << oral << "\n";
    cout << "PossibleInput: \n";
    PossibleInput pi;
    auto result = pi.find(oral);
    copy(result.begin(), result.end(), 
      ostream_iterator<decltype(result)::value_type>(cout, "\n"));
  }


  return 0;
}