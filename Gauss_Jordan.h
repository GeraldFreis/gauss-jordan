#ifndef GAUSS_JORDAN_H
#define GAUSS_JORDAN_H

#include "Matrix.h"
#include <queue>
#include <string>

class GaussJordan {
private:
	Matrix user_matrix;
	std::queue<std::string> commands;

public:
	GaussJordan(Matrix m);
	void solve();
};

#endif