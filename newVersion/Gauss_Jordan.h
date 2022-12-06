#ifndef GAUSS_JORDAN_H
#define GAUSS_JORDAN_H

#include "Matrix.h"
#include <queue>
#include <string>
#include <vector>

class GaussJordan {
private:
	Matrix user_matrix;
	int rows;
	int columns;
	std::queue<std::string> commands;

	bool isReduced();
	bool checkCombination(std::vector<std::string> current_combination);

public:
	GaussJordan(Matrix m);
	void solve();
	void printCommands();
	void printMatrix();
};

#endif