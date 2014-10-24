#ifndef _CSCMATRIX_H_
#define _CSCMATRIX_H_
#include <iostream>
using std::ostream;
#include "sparse_matrix.h"

class CSRMatrix;
class CSCMatrix {
public:
  CSCMatrix() : rowsize(0) {}
  CSCMatrix(const vector<vector<double>> &mat) {
    dense2csc(mat, val, row_ind, col_ptr);
    if (!mat.empty())
      rowsize = mat[0].size();
  }

  CSRMatrix transpose();
  vector<vector<double>> dense() const;

  int nnz() const {return val.size();}
  int row() const {return rowsize;}
  int col() const {return col_ptr.size() - 1;}

  vector<double> val;
  vector<int> row_ind;
  vector<int> col_ptr;

  friend class CSRMatrix;
  friend CSRMatrix operator * (const CSRMatrix &A, const CSCMatrix &B);
  friend ostream &operator << (ostream &os, const CSCMatrix &m);

private:
  int rowsize;
};
#endif