CC=clang++
CPP=CSCMatrix.cpp CSRMatrix.cpp test_matrix.cpp sparse_matrix.cpp COOMatrix.cpp
OBJ=$(CPP:.cpp=.o)
CXXFLAGS=-std=c++11

test-matrix: $(OBJ)
	clang++ -o $@ $(OBJ)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf *.o test-matrix