
BKTREE_CPP=test-BKtree.cpp BKtree.cpp levenshtein_distance.cpp
DESERIALIZE_CPP=deserialize.cpp BKtree.cpp levenshtein_distance.cpp
DIST_CPP=test-dist.cpp levenshtein_distance.cpp
bin=bktree test-dist deserialize

all: $(bin)

deserialize: $(DESERIALIZE_CPP)
	clang++ -std=c++11 -o $@ $(BKTREE_CPP) -lboost_serialization

bktree: $(BKTREE_CPP)
	clang++ -std=c++11 -o $@ $(BKTREE_CPP) -lboost_serialization

test-dist: $(DIST_CPP)
	clang++ -std=c++11 -o $@ $(DIST_CPP)

clean:
	rm -rf *.o $(bin)