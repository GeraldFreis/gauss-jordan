testingSolver: solver
	./solver

solver: Matrix.cpp Matrix.h Parser.cpp Solver.h Solver.cpp readingfile.cpp newmain.cpp	
	g++ Matrix.cpp Parser.cpp Solver.cpp readingfile.cpp newmain.cpp -o solver -std=c++17

testingTestingMain: testingMain
	./testingMain

testingMain: Matrix.cpp Matrix.h Parser.cpp Solver.h Solver.cpp readingfile.cpp testingmain.cpp
	g++ Matrix.cpp Parser.cpp Solver.cpp readingfile.cpp testingmain.cpp -o testingMain -std=c++17