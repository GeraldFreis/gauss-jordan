#ifndef GAUSS_JORDAN_H
#define GAUSS_JORDAN_H

#include "Matrix.h"
#include <queue>
#include <string>
#include <vector>

class GaussJordan {
private:
	Matrix user_matrix;
	std::queue<std::string> commands;

	void reduceColumn(int column_number, int pivot, int i);
	bool isReduced();
	void testCombination(std::vector<std::string> current_combination);

public:
	GaussJordan(Matrix m);
	void solve();
	void printCommands();
	void printMatrix();
};

#endif