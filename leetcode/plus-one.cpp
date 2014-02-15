#include "leetcode.h"

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
      vector<int> result(digits);
      int n = digits.size();
      bool carry = true;
      for (int i = n - 1; i >= 0; i--) {
        if (carry) {
          result[i] += 1;
          if (result[i] >= 10) {
            result[i] = 0;
            carry = true;
            if (i == 0)
              result.insert(result.begin(), 1);
          } else {
            break;
          }
        }
      }
      return result;
    }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  // int A[] = {9, 9, 1, 1, 9, 9};
  int A[] = {9, 9, 9, 9, 9, 9};
  // int A[] = {9};
  // int A[] = {8};
  int n = sizeof(A) / sizeof(n);
  vector<int> digits(A, A+n);

  copy(digits.begin(), digits.end(), ostream_iterator<int>(cout, ""));
  cout << '\n';
  auto result = sol.plusOne(digits);
  copy(result.begin(), result.end(), ostream_iterator<int>(cout, ""));
  cout << '\n';
  return 0;
}