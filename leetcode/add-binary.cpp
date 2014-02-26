#include "leetcode.h"

class Solution {
public:
  string addBinary(string a, string b) {
    int carry = 0;
    // always assume a is longer
    if (a.size() < b. size())
      swap(a, b);

    string result;
    int p = a.size() - 1, q = b.size() - 1;
    for (; q >= 0; p--, q--) {
      int ap = a[p] - '0';
      int bq = b[q] - '0';
      int sum = ap ^ bq ^ carry;
      result.push_back(sum + '0');
      carry = (ap & bq) | (carry & (ap ^ bq));
    }

    while (p >= 0) {
      int ap = a[p] - '0';
      int sum = ap ^ carry;
      result.push_back(sum + '0');
      carry = ap & carry;
      --p;
    }

    if (carry)
      result.push_back('1');

    std::reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  Solution sol;
  vector<string> a = {
    "111111",
    "0",
    "1",
    "1",
    "101",
  };
  vector<string> b = {
    "11",
    "0",
    "0",
    "1",
    "1"
  };

  for (int i = 0; i < a.size(); ++i) {
    cout << sol.addBinary(a[i], b[i]) << '\n';
  }
   
  return 0;
}