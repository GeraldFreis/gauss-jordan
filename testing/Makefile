testingMatrix: matrix
	./matrix

testingCombinations: combinations
	./combinations

matrix: ../Matrix.h ../Matrix.cpp testing_matrix_functions.cpp ../Parser.cpp
	g++ ../Parser.cpp ../Matrix.cpp testing_matrix_functions.cpp -o matrix -std=c++17

combinations: ../combinations.cpp testing_combinations.cpp
	g++ ../combinations.cpp testing_combinations.cpp -o combinations -std=c++17