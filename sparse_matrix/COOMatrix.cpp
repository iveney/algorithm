#include <cassert>
#include "COOMatrix.h"
using std::get;

COOMatrix::COOMatrix(const Matrix &mat) {
  if (mat.empty())
    return;

  row_ = mat.size();
  col_ = mat[0].size();

  for (int i = 0; i < row_; ++i) {
    for (int j = 0; j < col_; ++j) {
      ijv.push_back(std::make_tuple(i, j, mat[i][j]));
    }
  }
}

Matrix COOMatrix::dense() const {
  Matrix mat(row_, vector<double>(col_));
  for (auto &t : ijv) {
    int i, j, v;
    std::tie(i, j, v) = t;
    mat[i][j] = v;
  }
  return mat;
}

COOMatrix COOMatrix::transpose() const {
  COOMatrix tran(*this);
  for (auto &t : tran.ijv) {
    int i, j, v;
    std::tie(i, j, v) = t;
    t = std::make_tuple(j, i, v);
  }
  return tran;
}

COOMatrix operator * (COOMatrix &A, COOMatrix &B) {
  assert(A.col() == B.row());
  std::sort(A.ijv.begin(), A.ijv.end()); // sort by row
  std::sort(B.ijv.begin(), B.ijv.end(),
  [](const Triplet &a, const Triplet &b) { // by col
    if (std::get<1>(a) == std::get<1> (b)) {
      return std::get<0>(a) < std::get<0> (b);
    } else {
      return std::get<1>(a) < std::get<1> (b);
    }
  });

  COOMatrix C;
  C.row_ = A.row();
  C.col_ = B.col();
  int begi = 0, endi = 0;
  for (int i = 0; i < A.row(); ++i) {
    // search for the elements in row i: begi <= .. < endi
    endi = begi;
    while (get<0>(A.ijv[endi]) == i) {
      ++endi;
    }
    int curj = 0;
    double sum = 0;
    // compute the values for row i
    int k = begi, l = 0;
    while (l < B.ijv.size()) {
      if (k >= endi) {
        // finish curj
        k = begi;
      }
      int ai, aj, av, bi, bj, bv;
      std::tie(ai, aj, av) = A.ijv[k];
      std::tie(bi, bj, bv) = B.ijv[l];
      if (bj > curj) {
        if (!FZERO(sum))  {
          C.ijv.push_back(std::make_tuple(i, curj, sum));
          sum = 0;
        }
        curj = bj;
      }
      if (aj == bi) {
        sum += av * bv;
        ++k;
        ++l;
      } else if (aj > bi) {
        ++l;
      } else {
        ++k;
      }
    } // while
    // write the last column
    if (!FZERO(sum)) {
      C.ijv.push_back(std::make_tuple(i, curj, sum));
    }
    begi = endi;
  }
  return C;
}
