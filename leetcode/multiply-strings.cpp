#include "leetcode.h"

class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
      return "0";

    string sum = "0";
    int n1 = num1.size();
    for (int i = n1 - 1; i >= 0; --i) {
      string cur(n1 - 1 - i, '0');
      int carry = 0;
      for (int j = num2.size() - 1; j >= 0; --j) {
        int mul = (num1[i] - '0') * (num2[j] - '0') + carry;
        carry = mul / 10;
        mul %= 10;
        cur.push_back(mul + '0');
      }
      if (carry > 0)
        cur.push_back(carry + '0');
      reverse(cur.begin(), cur.end());
      // printf("i=%d, cur=%s\n", i, cur.c_str());
      sum = add(sum, cur);
    }
    return sum;
  }

  string add(string num1, string num2) {
    int i = num1.size() - 1, j = num2.size() - 1;
    int carry = 0;
    string result;
    while (i >= 0 || j >= 0) {
      int sum = carry;
      if (i >= 0) {
        sum += num1[i] - '0';
        --i;
      }
      if (j >= 0) {
        sum += num2[j] - '0';
        --j;
      }

      carry = sum / 10;
      sum %= 10;
      // printf("s = %d c = %d\n", sum, carry);
      result.push_back('0' + sum);
    }

    // don't forget the carry
    if (carry)
      result.push_back('0' + carry);
    reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  Solution sol;
  vector<string> num1 {
    "33",
    "23417",
    "0",
    "1234",
    "0",
    "1010",
    "99",
  };
  vector<string> num2 {
    "444",
    "199718",
    "1234",
    "0",
    "0",
    "201",
    "99",
  };

  for (int i = 0; i < num1.size(); ++i) {
    cout << sol.multiply(num1[i], num2[i]) << endl;
  }
  
  return 0;
}