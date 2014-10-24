#ifndef _CSRMATRIX_H_
#define _CSRMATRIX_H_ 
#include "sparse_matrix.h"
#include <iostream>
using std::ostream;

class CSCMatrix;
class CSRMatrix {
public:
  CSRMatrix() : colsize(0) {}
  CSRMatrix(const vector<vector<double>> &mat) {
    dense2csr(mat, val, col_ind, row_ptr);
    if (!mat.empty())
      colsize = mat[0].size();
  }

  CSCMatrix transpose();
  vector<vector<double>> dense() const;

  int nnz() const {return val.size();}
  int row() const {return row_ptr.size() - 1;}
  int col() const {return colsize;}

  vector<double> val;
  vector<int> col_ind;
  vector<int> row_ptr;

  friend class CSCMatrix;
  friend ostream & operator << (ostream &os, const CSRMatrix &s);
  friend CSRMatrix operator * (const CSRMatrix &A, const CSCMatrix &B);

private:
  int colsize;
};

#endif