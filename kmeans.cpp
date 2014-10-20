#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <limits>
using namespace std;

const double EPSILON = 1e-5;

struct Point {
  double x, y;
};

ostream &operator << (ostream& os, const Point& p) {
  return os << p.x << " " << p.y;
}

double euclidean_square(const Point &a, const Point &b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return dx * dx + dy * dy; 
}

// generate n points in a normal distribution (x, y uncorrelated)
vector<Point> sampleNormal(Point center, double sx, double sy, int n) {
  // static std::random_device rd;
  static std::mt19937 gen;
  vector<Point> points;
  std::normal_distribution<> x(center.x, sx);
  std::normal_distribution<> y(center.y, sy);
  for (int i = 0; i < n; ++i) {
    points.push_back(Point{x(gen), y(gen)});
  }
  return points;
}

// returns the center of clusters, and the assignment (in 'cluster')
vector<Point> kmeans(vector<Point> &points, int k, vector<int> &cluster) {
  vector<Point> centers(k, {0.0});
  int n = points.size();
  // uniformly select k points as centers
  for (int i = 0; i < k; ++i) {
    centers[i] = points[i * ceil(n/k)];
  }

  // initialize cluster
  cluster.resize(n);
  for (int i = 0; i < n; ++i) {
    cluster[i] = i % k;
  }

  const int max_iter = 100;
  int iter = 0;
  double diff = 0.0;
  do {
    // compute new centroids
    vector<Point> newc(k, {0, 0});
    vector<int> csize(k);
    diff = 0.0;
    for (int i = 0; i < n; ++i) {
      newc[cluster[i]].x += points[i].x;
      newc[cluster[i]].y += points[i].y;
      ++csize[cluster[i]];
    }

    // compute the residue of centroid moves
    for (int i = 0; i < k; ++i) {
      newc[i].x /= csize[i];
      newc[i].y /= csize[i];
      // cout << "New c: " << i << " " << newc[i] << " size " << csize[i] << "\n";
      // cout << "Old c: " << i << " " << centers[i] << " size " << csize[i] << "\n";
      diff += euclidean_square(newc[i], centers[i]);
    }

    // assign points to the new center
    for (int i = 0; i < n; ++i) {
      int minj = -1;
      double min_dist = numeric_limits<double>::max();
      for (int j = 0; j < k; ++j) {
        double dist = euclidean_square(points[i], newc[j]);
        if (dist < min_dist) {
          min_dist = dist;
          minj = j;
        }
      }
      cluster[i] = minj;
      // cout << i << " -> " << minj << "\n";
    }

    centers = newc;
    // cout << "new diff: " << diff << "\n";
  } while (diff > EPSILON && ++iter < max_iter);
  return centers;
}

int main(int argc, char const *argv[]) {
  // generate 2 gaussian samples
  vector<Point> p1 = sampleNormal({1.0, 2.0}, 1.0, 2.0, 50);
  vector<Point> p2 = sampleNormal({-1.0,-1.0}, 1.0, 1.5, 50);
  vector<Point> points;
  points.insert(points.end(), p1.begin(), p1.end());
  points.insert(points.end(), p2.begin(), p2.end());

  vector<int> cluster;
  vector<Point> centers = kmeans(points, 2, cluster);
  copy(points.begin(), points.end(), 
    ostream_iterator<decltype(points)::value_type>(cout, "\n"));
  copy(centers.begin(), centers.end(), 
    ostream_iterator<decltype(centers)::value_type>(cout, "\n"));

  return 0;
}