#include <iostream>
using namespace std;

#include "sparse_matrix.h"
#include "CSCMatrix.h"
#include "CSRMatrix.h"
#include "COOMatrix.h"

void test_dense2csr(const vector<vector<double>> &mat) {
  CSRMatrix s(mat);
  cout << s << "\n";
  cout << "Dense :\n";
  cout << s.dense() << "\n";
  CSCMatrix t = s.transpose();
  cout << t << "\n";
  cout << "Dense :\n";
  cout << t.dense() << "\n";

  auto r = s * t;
  cout << "s * t:\n";
  cout << r << "\n";
  cout << "Dense :\n";
  cout << r.dense() << "\n";
}

void test_dense2csc(const vector<vector<double>> &mat) {
  CSCMatrix s(mat);

  cout << s.dense() << "\n";
}

void test_coo(const vector<vector<double>> &mat) {
  COOMatrix s(mat);
  COOMatrix t = s.transpose();
  cout << s.dense() << "\n";
  cout << t.dense() << "\n";
  cout << (s * t).dense() << "\n";
}

int main(int argc, char const *argv[])
{
  vector<vector<double>> mat {
    {10, 0, 0, 0, -2, 0},
    {3, 9, 0, 0, 0, 3},
    {0, 7, 8, 7, 0, 0},
    {3, 0, 8, 7, 5, 0},
    {0, 8, 0, 9, 9, 13},
    {0, 4, 0, 0, 2, -1},
  };

  test_dense2csr(mat);
  // test_dense2csc(mat);
  test_coo(mat);
  return 0;
}