testingMatrix: matrix
	./matrix

matrix: ../Matrix.h ../Matrix.cpp testing_matrix_functions.cpp ../Parser.cpp
	g++ ../Parser.cpp ../Matrix.cpp testing_matrix_functions.cpp -o matrix -std=c++17

testingCombinations: combinations
	./combinations

combinations: ../combinations.cpp testing_combinations.cpp
	g++ ../combinations.cpp testing_combinations.cpp -o combinations -std=c++17

testingGaussJordan: gaussjordan
	./gaussjordan

gaussjordan: ../Gauss_Jordan.h ../Gauss_Jordan.cpp ../combinations.cpp ../Parser.cpp testing_gauss_jordan.cpp ../Matrix.h ../Matrix.cpp
	g++ ../Gauss_Jordan.cpp ../Matrix.cpp ../combinations.cpp ../Parser.cpp testing_gauss_jordan.cpp -o gaussjordan -std=c++17


