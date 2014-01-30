// http://oj.leetcode.com/problems/search-insert-position/

#include <iostream>
using namespace std;

class Solution {
public:
  int searchInsert(int A[], int n, int target) {
    if (n <= 0) return 0;
    int b = 0, e = n - 1;
    while (b < e) {
      int mid = (b+e)/2;
      if (A[mid] == target)
        return mid;
      else if (A[mid] < target) {
        b = mid + 1;
      } else {
        e = mid - 1;
      }
    }

    // b == e
    int ret;
    if (A[b] == target)
      ret = b;
    else if (A[b] < target)
      ret = b + 1;
    else
      ret = b;

    return ret;
  }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  int A[] = {1,3,5,6};
  cout << sol.searchInsert(A, 4, 5) << endl;
  cout << sol.searchInsert(A, 4, 2) << endl;
  cout << sol.searchInsert(A, 4, 7) << endl;
  cout << sol.searchInsert(A, 4, 0) << endl;
  cout << sol.searchInsert(A, 4, 1) << endl;

  int B[] = {1, 3};
  cout << sol.searchInsert(B, 2, 2) << endl;
  return 0;
}