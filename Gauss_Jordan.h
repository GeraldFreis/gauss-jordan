#ifndef GAUSS_JORDAN_H
#define GAUSS_JORDAN_H

#include "Matrix.h"
#include <queue>
#include <string>

class GaussJordan {
private:
	Matrix user_matrix;
	std::queue<std::string> commands;

	void reduceColumn(int column_number, int pivot, int i);
	bool isReduced();

public:
	GaussJordan(Matrix m);
	void solve();
	void printCommands();
};

#endif