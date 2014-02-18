// Idea: traverse the lands and find sinks
// expand from the sink as wavefront using BFS.
// Each land is visited at most twice. Thus O(S^2) 

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using std::vector;
using std::queue;
using std::pair;
using std::make_pair;

class RainfallTest {
public:
  RainfallTest(int size) : S(size), nbasin(0) {
    memset(basin, 0, sizeof(basin));
  };

  // C-style output is faster, but 1000x1000 isn't really big
  void initFromStream(FILE* stream) {
    for (int i = 0; i < S; ++i) {
      for (int j = 0; j < S; ++j) {
        fscanf(stream, "%d", &land[i][j]);
      }
    }
  }

  // the main routine to flood fill the basins
  void computeBasins() {
    for (int i = 0; i < S; ++i) {
      for (int j = 0; j < S; ++j) {
        if (basin[i][j] == 0 && isSink(i, j)) {
          ++nbasin;
          int size = expand(i, j);
          basin_size.push_back(size);
        }
      } // for j
    } // for i
  }

  // output to stdout
  void outputBasinSize() {
    std::sort(basin_size.begin(), basin_size.end(), [](int a, int b){
      return b < a;
    });

    printf("%d", basin_size[0]);
    for (int i = 1; i < basin_size.size(); ++i)
      printf(" %d", basin_size[i]);
  }

private:
  // BFS from given land index
  // returns size of this basin
  int expand(int i, int j) {
    typedef pair<int, int> Index;
    queue<Index> myqueue;
    myqueue.push(make_pair(i, j));
    int r, c;
    int size = 0;
    while ( !myqueue.empty() ) {
      // std::tie can't work in interviewstreet, probably old version of g++
      Index p = myqueue.front();
      r = p.first; c = p.second;
      myqueue.pop();
      basin[r][c] = nbasin;
      ++size;

      // traverse the unvisited neighbor
      for (int k = 0; k < N; ++k) {
        int ii = r + di[k], jj = c + dj[k];
        if ( isValidIndex(ii, jj) && basin[ii][jj] == 0 &&
             flowTo(ii, jj, r, c) )
          myqueue.push(make_pair(ii, jj));
      }
    } // while

    return size;
  }

  // find and test if (r, c) is the lowest neighbor of of (i, j)
  // i.e., flow from (i, j) to (r, c)
  bool flowTo(int i, int j, int r, int c) {
    int minr = i, minc = j;
    for (int k = 0; k < N; ++k) {
      int ii = i + di[k], jj = j + dj[k];
      if ( isValidIndex(ii, jj) && land[ii][jj] < land[minr][minc] ) {
        minr = ii;
        minc = jj;
      }
    }
    return (minr == r && minc == c);
  }

  // tests valid bound
  bool isValidIndex(int i, int j) const {
    return (0 <= i && i < S && 0 <= j && j < S);
  }

  // determines if the given land is a sink
  bool isSink(const int i, const int j) const {
    const int di[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    const int dj[] = {-1,  0,  1, -1, 1, -1, 0, 1};
    const int n = 8;
    for (int k = 0; k < N; ++k) {
      int ii = i + di[k], jj = j + dj[k];
      if ( isValidIndex(ii, jj) && land[ii][jj] < land[i][j] )
          return false;
    }

    return true;
  }

  // for neighbor traversal
  const int di[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
  const int dj[8] = {-1,  0,  1, -1, 1, -1, 0, 1};
  const int N = 8;
  
  int S;
  int nbasin;
  const static int MAXSIZE = 1000;
  int land[MAXSIZE][MAXSIZE];
  int basin[MAXSIZE][MAXSIZE];
  vector<int> basin_size;
};

int main() {
  int S;
  scanf("%d", &S);
  RainfallTest rainfall(S);
  rainfall.initFromStream(stdin);
  rainfall.computeBasins();
  rainfall.outputBasinSize();
  return 0;
}