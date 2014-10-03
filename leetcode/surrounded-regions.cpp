#include <queue>
#include "leetcode.h"
#include "array2D.hpp"


class Solution {
public:
  void propagate(vector<vector<char> > &board, 
                 vector<vector<char> > &copy,
                 vector<vector<bool> > &visited,
                 int i, int j) {

    int m = board.size();
    int n = board[0].size();

    const vector<pair<int, int> > nbrs = {
      make_pair(-1, 0),
      make_pair( 1, 0),
      make_pair( 0, -1),
      make_pair( 0,  1),
    };
    queue<pair<int, int> > q;
    q.push(make_pair(i, j));
    while (!q.empty()) {
      int r, c;
      tie(r, c) = q.front();
      board[r][c] = copy[r][c] = 'O';
      visited[r][c] = true;
      q.pop();
      // explore neighbor and mark the corresponding location in 'copy'
      for (auto nbr : nbrs) {
        int nr = r + nbr.first, nc = c + nbr.second;
        if ( nr < 0 || nr >= m ||
             nc < 0 || nc >= n ||
             visited[nr][nc] ||
             board[nr][nc] == 'X') {
          continue;
        }
        q.push(make_pair(nr, nc));
        visited[nr][nc] = true;
      }
    } // while
  }

  void solve(vector<vector<char> > &board) {
    int m = board.size();
    if (m == 0) return;
    int n = board[0].size();
    if (n == 0) return;

    vector<vector<char> > copy(m, vector<char>(n, 'X'));
    vector<vector<bool> > visited(m, vector<bool>(n, false));

    // examine the boarder and propagate from there : top and bottom row
    for (int i : vector<int> {0, m-1}) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'O' && copy[i][j] == 'X' && !visited[i][j]) {
          // if copy[i][j] is also O means it's already reached
          propagate(board, copy, visited, i, j);
        }
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j : vector<int> {0, n-1}) {
        if (board[i][j] == 'O' && copy[i][j] == 'X' && !visited[i][j]) {
          propagate(board, copy, visited, i, j);
        }
      }
    }

    board = copy;
  }

  void solve2(vector<vector<char>> &board) {
    int m = board.size();
    if (m == 0) return;
    int n = board[0].size();
    if (n == 0) return;

    const int drs[] =  {-1, 1};
    const int dcs[]  = {-1, 1};
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'X') {
          continue;
        }

        queue<pair<int, int> > q, bak;
        int r, c;
        q.push(make_pair(i, j));
        bool skip = false;
        while (!q.empty()) {
          tie(r, c) = q.front();
          q.pop();

          // explore neighbor and check if it is adjacent to wall
          for (auto dr : drs) {
            for (auto dc : dcs) {
              int nr = r + dr, nc = c + dc;
              if ( nr < 0 || nr > m ||
                   nc < 0 || nc > n) {
                skip = true;
                break;
              }
              if (board[nr][nc] == 'O') {
                q.push(make_pair(nr, nc));
              }
            }
            if (skip) break;
          }

          if (!skip) {
            bak.push(make_pair(r, c));
          } else {
            break;
          }
        } // while

        if (!skip) {
          while (!bak.empty()) {
            tie(r, c) = bak.front();
            bak.pop();
            board[r][c] = 'X';
          }
        }
      } // for j
    } // for i

  }
};

int main() {
  // vector<vector<char> > board = {
  //   {'X', 'X', 'X', 'X'},
  //   {'X', 'O', 'O', 'X'},
  //   {'X', 'X', 'O', 'X'},
  //   {'X', 'O', 'X', 'X'},
  // };
  // vector<vector<char> > board = {
  //   {'O', 'O'},
  //   {'O', 'O'},
  // };
  char b[20][21] = {
    "XOOOOOOOOOOOOOOOOOOO",
    "OXOOOOXOOOOOOOOOOOXX",
    "OOOOOOOOXOOOOOOOOOOX",
    "OOXOOOOOOOOOOOOOOOXO",
    "OOOOOXOOOOXOOOOOXOOX",
    "XOOOXOOOOOXOXOXOXOXO",
    "OOOOXOOXOOOOOXOOXOOO",
    "XOOOXXXOXOOOOXXOXOOO",
    "OOOOOXXXXOOOOXOOXOOO",
    "XOOOOXOOOOOOXXOOXOOX",
    "OOOOOOOOOOXOOXOOOXOX",
    "OOOOXOXOOXXOOOOOXOOO",
    "XXOOOOOXOOOOOOOOOOOO",
    "OXOXOOOXOXOOOXOXOXOO",
    "OOXOOOOOOOXOOOOOXOXO",
    "XXOOOOOOOOXOXXOOOXOO",
    "OOXOOOOOOOXOOXOXOXOO",
    "OOOXOOOOOXXXOOXOOOXO",
    "OOOOOOOOOOOOOOOOOOOO",
    "XOOOOXOOOXXOOXOXOXOO",
  };
  Array2D<char>::type board = fromCArray((char*)b, 20, 21);
  // remove the NULL char
  for (auto &row : board)
    row.resize(20);

  print_2D<char>(board);
  Solution sol;
  sol.solve(board);
  print_2D<char>(board);
  
  return 0;
}