#include <cassert>
#include "CSCMatrix.h"
#include "CSRMatrix.h"
using std::ostream_iterator;

CSRMatrix CSCMatrix::transpose() {
  CSRMatrix t;
  t.val = val;
  t.col_ind = row_ind;
  t.row_ptr = col_ptr;
  t.colsize = rowsize;
  return t;
}

vector<vector<double>> CSCMatrix::dense() const {
  vector<vector<double>> d(row(), vector<double>(col()));

  for (int j = 0; j < col_ptr.size() - 1; ++j) {
    for (int k = col_ptr[j]; k < col_ptr[j+1]; ++k) {
      d[row_ind[k]][j] = val[k];
    }
  }
  return d;
}

CSRMatrix operator * (const CSRMatrix &A, const CSCMatrix &B) {
  assert(A.col() == B.row());
  CSRMatrix C; // m x n . n x k => m x k

  C.colsize = B.col();
  C.row_ptr.resize(A.row() + 1);
  C.row_ptr[0] = 0;
  for (int i = 0; i < A.row_ptr.size() - 1; ++i) {
    // row i : elements between row_ptr[i] .. row_ptr[i+1]
    for (int j = 0; j < B.col_ptr.size() - 1; ++j) {
      // col j : elements between col_ptr[j] .. col_ptr[j+1]
      int k = A.row_ptr[i], l = B.col_ptr[j];
      double sum = 0;
      while (k < A.row_ptr[i+1] && l < B.col_ptr[j+1]) {
        if (A.col_ind[k] == B.row_ind[l]) {
          sum += A.val[k] * B.val[l];
          ++k;
          ++l;
        } else if (A.col_ind[k] < B.row_ind[l]) {
          ++k;
        } else {
          ++l;
        }
      } // while
      if (FZERO(sum)) continue;
      C.val.push_back(sum);
      C.col_ind.push_back(j);
    } // j
    C.row_ptr[i+1] = C.val.size();
  } // i
  return C;
}

ostream &operator << (ostream &os, const CSCMatrix &s) {
  os << s.row() << " x " << s.col();
  os << "\nval: ";
  copy(s.val.begin(), s.val.end(), 
    ostream_iterator<decltype(s.val)::value_type>(os, " "));
  os << "\nrow_ind: ";
  copy(s.row_ind.begin(), s.row_ind.end(), 
    ostream_iterator<decltype(s.row_ind)::value_type>(os, " "));
  os << "\ncol_ptr: ";
  copy(s.col_ptr.begin(), s.col_ptr.end(), 
    ostream_iterator<decltype(s.col_ptr)::value_type>(os, " "));
  return os;
}