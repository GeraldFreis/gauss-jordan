testingMatrix: matrix
	./matrix

matrix: ../Matrix.h ../Matrix.cpp testing_matrix_functions.cpp ../Parser.cpp
	g++ ../Parser.cpp ../Matrix.cpp testing_matrix_functions.cpp -o matrix -std=c++17