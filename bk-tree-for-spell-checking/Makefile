
BKTREE_CPP=test-BKtree.cpp BKtree.cpp levenshtein_distance.cpp
DIST_CPP=test-dist.cpp levenshtein_distance.cpp

all: bktree dist

bktree: $(BKTREE_CPP)
	clang++ -std=c++11 -o test-BKtree $(BKTREE_CPP)

dist: $(DIST_CPP)
	clang++ -std=c++11 -o test-dist $(DIST_CPP)