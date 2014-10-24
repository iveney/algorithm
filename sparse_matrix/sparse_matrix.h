#ifndef _SPARSE_MATRIX_H_
#define _SPARSE_MATRIX_H_

#include <cmath>
#include <vector>
#include <iostream>
using std::vector;
using std::abs;
using std::ostream;

#define FPRECISION 1e-6
#define FZERO(x) (abs(x) < FPRECISION)

typedef vector<vector<double>> Matrix;

// dense matrix to csr
void dense2csr(const Matrix &mat,
               vector<double> &val, vector<int> &col_ind, vector<int> &row_ptr); 

// dense matrix to csc
void dense2csc(const Matrix &mat,
               vector<double> &val, vector<int> &row_ind, vector<int> &col_ptr);

ostream &operator << (ostream &os, const Matrix &mat);

#endif