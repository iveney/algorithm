#ifndef _COOMATRIX_H_
#define _COOMATRIX_H_

#include <utility>
#include "sparse_matrix.h"

typedef std::tuple<int, int, double> Triplet;

class COOMatrix {
public:
  COOMatrix() : row_(0), col_(0){};
  COOMatrix(const Matrix &mat);
  int row() {return row_;}
  int col() {return col_;}

  Matrix dense() const;
  COOMatrix transpose() const;

  vector<Triplet> ijv;
  friend COOMatrix operator * (COOMatrix &A, COOMatrix &B);
private:
  int row_;
  int col_;
};

#endif
