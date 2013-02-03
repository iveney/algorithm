#include "quadtree.h"

void QuadTree::deleteSelf() {
  if (NW_ != NULL) {
    NW_->deleteSelf();
    NW_ = NULL;
  }

  if (NE_ != NULL) {
    NE_->deleteSelf();
    NE_ = NULL;
  }

  if (SW_ != NULL) {
    SW_->deleteSelf();
    SW_ = NULL;
  }

  if (SE_ != NULL) {
    SE_->deleteSelf();
    SE_ = NULL;
  }
}

void QuadTree::splitSelf() {
  double w = box_.half_width_ / 2;
  double h = box_.half_height_ / 2;
  double cx = box_.center_.x_;
  double cy = box_.center_.y_;
  NW_ = new QuadTree(Box(Point(cx - w/2, cy + h/2), w, h));
  NE_ = new QuadTree(Box(Point(cx + w/2, cy + h/2), w, h));
  SW_ = new QuadTree(Box(Point(cx - w/2, cy - h/2), w, h));
  SE_ = new QuadTree(Box(Point(cx + w/2, cy - h/2), w, h));
}

bool QuadTree::insertPoint(const Point &pt) {
  if ( !box_.containsPoint(pt) )
    return false;

  if (plist_.size() < MAX_POINTS) {
    plist_.push_back(pt);
    return true;
  } else {
    // split
    if (NW_ == NULL) splitSelf();

    if (NW_->insertPoint(pt)) return true;
    if (NE_->insertPoint(pt)) return true;
    if (SW_->insertPoint(pt)) return true;
    if (SE_->insertPoint(pt)) return true;

    return false;
  }
}

vector<Point> QuadTree::queryRange(const Box &range) {
  vector<Point> pointsInRange;

  for (int i = 0; i < plist_.size(); i++) {
    if (range.containsPoint(plist_[i]))
      pointsInRange.push_back(plist_[i]);
  }

  if (NW_ != NULL) {
    vector<Point> pts;

    pts = NW_->queryRange(range);
    copy(pts.begin(), pts.end(), back_inserter(pointsInRange));

    pts = NE_->queryRange(range);
    copy(pts.begin(), pts.end(), back_inserter(pointsInRange));

    pts = SW_->queryRange(range);
    copy(pts.begin(), pts.end(), back_inserter(pointsInRange));

    pts = SE_->queryRange(range);
    copy(pts.begin(), pts.end(), back_inserter(pointsInRange));
  }

  return pointsInRange;
}
