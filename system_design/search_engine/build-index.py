#!/usr/bin/env python
from os import listdir
from os.path import isfile, join
from collections import defaultdict
import sys
import pickle
import math
import re

# build inverted index given a corpus directory

# tf: reverse index and term frequency, e.g.,
# cat: {1.txt: 0.2, 2.txt: 0.5}

# idf: inverse document frequency
# idf(x) = log (Ndocs / Ndoc has x )
# e.g.,
# {cat: 0.5, dog: 0.2}

# this is for serialization
def defaultfloat():
  return defaultdict(float)

def build(path, output):
  files = [ f for f in listdir(path) if isfile(join(path,f)) ]
  tf = defaultdict(defaultfloat)
  idf = defaultdict(float)
  for fname in files:
    fullname = path + "/" + fname
    with open(fullname) as f:
      nwords = 0
      for line in f:
        for word in line.replace(',', '').split():
          nwords += 1
          # update reverse index
          tf[word][fullname] = (tf[word][fullname] + 1) / nwords
          idf[word] = math.log(1.0 * len(files) / len(tf[word]))

  with open(output, 'wb') as f:
    pickle.dump(tf, f)
    pickle.dump(idf, f)


if __name__ == "__main__":
  build(sys.argv[1], sys.argv[2])
