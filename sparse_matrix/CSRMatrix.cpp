#include "CSRMatrix.h"
#include "CSCMatrix.h"
using std::ostream_iterator;

CSCMatrix CSRMatrix::transpose() {
  CSCMatrix s;
  s.val = val;
  s.row_ind = col_ind;
  s.col_ptr = row_ptr;
  s.rowsize = colsize;
  return s;
}

ostream & operator << (ostream &os, const CSRMatrix &s) {
  os << s.row() << " x " << s.col();
  os << "\nval: ";
  copy(s.val.begin(), s.val.end(), 
    ostream_iterator<decltype(s.val)::value_type>(os, " "));
  os << "\ncol_ind: ";
  copy(s.col_ind.begin(), s.col_ind.end(), 
    ostream_iterator<decltype(s.col_ind)::value_type>(os, " "));
  os << "\nrow_ptr: ";
  copy(s.row_ptr.begin(), s.row_ptr.end(), 
    ostream_iterator<decltype(s.row_ptr)::value_type>(os, " "));
  return os;
}

vector<vector<double>> CSRMatrix::dense() const {
  vector<vector<double>> d(row(), vector<double>(col()));

  for (int i = 0; i < row_ptr.size() - 1; ++i) {
    for (int k = row_ptr[i]; k < row_ptr[i+1]; ++k) {
      d[i][col_ind[k]] = val[k];
    }
  }
  return d;
}
