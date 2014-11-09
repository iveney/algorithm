#!/usr/bin/env python

# main features
#
# build-index.py <corpus dir> <tfidf> build the inverted index with tf-idf, and serialize them into data
# search.py <tfidf> <query string> computes the TF-IDF, returns the ranked documents and the score
#
# TODO: consider stoplist

import sys
import pickle
from collections import defaultdict
import operator


# this is for serialization
def defaultfloat():
  return defaultdict(float)

def search(indexpath, query):
  with open(indexpath, 'rb') as f:
    tf = pickle.load(f)
    idf = pickle.load(f)

  # generate candidate file list
  scores = defaultdict(float)
  for word in set(query.split()):
    for fname, tfword in tf[word].iteritems():
      scores[fname] += tfword * idf[word]
    # candidates |= set(tf[word].keys())

  sorted_scores = sorted(scores.items(), key=operator.itemgetter(1), reverse=True)
  print sorted_scores


if __name__ == "__main__":
  search(sys.argv[1], sys.argv[2])