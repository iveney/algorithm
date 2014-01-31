#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
      int sum = A[0], mm = A[0];
      for (int i = 1; i < n; ++i) {
        if (sum < 0 && A[i] >= 0) {
          sum = A[i];
        }
        else if (sum + A[i] > 0) {
          sum += A[i];
        }
        else {
          sum = A[i];
        }
        if (sum > mm) mm = sum;
      }
      return mm;
    }
};

int main(int argc, char const *argv[])
{
  // int A[] = {-2,1,-3,4,-1,2,1,-5,4};
  int A[] = {-2,-3,-1,-5};
  int n = sizeof(A) / sizeof(int);
  Solution sol;
  int sum = sol.maxSubArray(A, n);
  cout << sum << endl;
  return 0;
}