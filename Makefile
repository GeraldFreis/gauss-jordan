testingSolver: solver
	clear
	./solver

solver: Matrix.cpp Matrix.h Parser.cpp main.cpp	
	g++ Matrix.cpp Parser.cpp main.cpp -o solver -std=c++17
