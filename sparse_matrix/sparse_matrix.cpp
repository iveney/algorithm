#include <iomanip>
#include "sparse_matrix.h"

// dense matrix to csr
void dense2csr(const vector<vector<double>> &mat,
               vector<double> &val, vector<int> &col_ind, vector<int> &row_ptr) {
  if (mat.empty()) return;
  int m = mat.size();
  int n = mat[0].size();

  val.clear();
  col_ind.clear();
  row_ptr.resize(m + 1);
  row_ptr[0] = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (FZERO(mat[i][j])) {
        continue;
      }
      val.push_back(mat[i][j]);
      col_ind.push_back(j);
    }
    row_ptr[i+1] = val.size();
  }
}

// dense matrix to csc
void dense2csc(const vector<vector<double>> &mat,
               vector<double> &val, vector<int> &row_ind, vector<int> &col_ptr) {
  if (mat.empty()) return;
  int m = mat.size();
  int n = mat[0].size();

  val.clear();
  row_ind.clear();
  col_ptr.resize(n + 1); // 
  col_ptr[0] = 0;
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < m; ++i) {
      if (FZERO(mat[i][j])) {
        continue;
      }
      val.push_back(mat[i][j]);
      row_ind.push_back(i);
    }
    col_ptr[j+1] = val.size();
  }
}

ostream &operator << (ostream &os, const Matrix &mat) {
  for (auto row : mat) {
    for (auto x : row) {
      os << std::setw(4) << x;
    }
    os << "\n";
  }
  return os;
}

// csr to csc
#include "CSCMatrix.h"
#include "CSRMatrix.h"