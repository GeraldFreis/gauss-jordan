testingSolver: solver
	./solver

solver: Matrix.cpp Matrix.h Parser.cpp Solver.h Solver.cpp main.cpp	
	g++ Matrix.cpp Parser.cpp Solver.cpp main.cpp -o solver -std=c++17
