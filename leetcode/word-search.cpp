#include "leetcode.h"
#include "array2D.hpp"

class Solution {
public:
  // neighbors: up, down, left, right
  int di[4] {-1, 1, 0,  0};
  int dj[4] {0, 0,  -1, 1};
  int M, N;

  bool exist(vector<vector<char> > &board, string word) {
    if (word.empty()) return true;
    M = board.size();
    if (M == 0) return false;
    N = board[0].size();
    if (N == 0) return false;

    vector<vector<bool> > visited(M);
    for (auto &v : visited) {
      v.assign(N, false);
    }

    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (board[i][j] == word[0] && find_word(board, visited, i, j, word, 0))
          return true;
      }
    }

    return false;
  }

  inline bool valid(int ii, int jj) {
    return (ii >= 0 && ii < M && jj >= 0 && jj < N);
  }

  bool find_word(vector<vector<char> > &board, vector<vector<bool> > &visited,
                 int i, int j,
                 string &word, int pos) {
    if (visited[i][j])
      return false;
    if (board[i][j] != word[pos])
      return false;

    // !visited[i][j] && board[i][j] == word[pos]
    if (pos+1 ==word.size()) return true;

    visited[i][j] = true;
    for (int k = 0; k < 4; ++k) {
      int ii = i + di[k];
      int jj = j + dj[k];
      if (valid(ii, jj) && 
          find_word(board, visited, ii, jj, word, pos + 1))
        return true;
    }
    visited[i][j] = false;
    return false;
  }
};

int main() {
  Solution sol;
  vector<string> data {
    "ABCE",
    "SFCS",
    "ADEE"
  };

  vector<vector<char> > board(data.size());
  for (int i = 0; i < data.size(); ++i) {
    board[i].assign(data[i].begin(), data[i].end());
  }

  print_2D<char>(board);
  vector<string> words {
    "ABCCED",
    "SEE",
    "ABCB",
    "ASADFBCCEESE",
    "ESECBASADECF",
    "SFCSECBA",
    "SFCSECBAE",
  };

  for (auto s : words) {
    cout << sol.exist(board, s) << endl;
  }
  
  return 0;
}