#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;


// helper recursive function
// B is buffer for 2-way merge
void mergesort(int *A, int b, int e, int *B) {
    if (b >= e) return;
    int mid = (b+e) / 2;
    mergesort(A, b, mid, B);
    mergesort(A, mid+1, e, B);
    
    // 2-way merge in place
    int count =  e - b + 1;
    memcpy(B+b, A+b, sizeof(int) * count);
    int pl = b;
    int pr = mid+1;
    int i = b;
    while (pl <= mid && pr <= e) {
        if (B[pl] <= B[pr]) {
            A[i] = B[pl];
            pl++;
        } else {
            A[i] = B[pr];
            pr++;
        }
        i++;
    }
    
    // copy the remain element in B if left part has remains
    // no need to copy right part since it is in place
    int remain = mid - pl + 1;
    for (int j = 0; j < remain; ++j) {
        A[i++] = B[pl++];
    }
}


// calling interface
void mergesort(int *A, int n) {
    int *B = new int[n];
    mergesort(A, 0, n-1, B);
    delete [] B;
}

int main() {
    int A[] = {5,-3,1,3,4,4,5,7,0,2,9,6};
    // int A[] = {5,-3, 1, 4, 6};
    int n = sizeof(A) / sizeof(int);
    mergesort(A, n);
    copy(A, A+n, ostream_iterator<int>(cout, " "));
    cout << '\n';
    return 0;
}