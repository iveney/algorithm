#include <iterator>
#include <iostream>
using namespace std;

int partition(int *A, int b, int e) {
  int v = A[b];
  swap(A[b], A[e]);
  int p = b;
  for (int i = b; i < e; i++) {
    if (A[i] <= v) {
      swap(A[i], A[p]);
      ++p;
    }
  }
  swap(A[p], A[e]);
  return p;
}

void qsort(int *A, int b, int e) {
  if (b >= e) return;

  int pivot = partition(A, b, e);

  qsort(A, b, pivot-1);
  qsort(A, pivot+1, e);
}

void mergesort(int *A, int b, int e) {
  if (b >= e) return;

  int mid = (b+e) / 2;
  mergesort(A, b, mid);
  mergesort(A, mid+1, e);

  // 2-way merge
  int n1 = mid-b+1;
  int n2 = e-mid;
  int *left = new int[n1];
  int *right = new int[n2];
  memcpy(left, A+b, n1*sizeof(int));
  memcpy(right, A+mid+1, n2*sizeof(int));

  int i = 0, j = 0;
  int p = b;
  while (p <= e) {
    if ( i < n1 && (j >= n2 || left[i] <= right[j]) ) {
      A[p++] = left[i++];
    } else {
      A[p++] = right[j++];
    }
  }
  delete [] left;
  delete [] right;
}

int main(int argc, char const *argv[])
{
  int a[] = {2,8,6,3,4,2,7,0,1,-5,2};
  int n = sizeof(a) / sizeof(int);
  // qsort(a, 0, n-1);
  mergesort(a, 0, n-1);
  copy(a, a+n, ostream_iterator<int>(cout, " "));
  cout << '\n';
  return 0;
}