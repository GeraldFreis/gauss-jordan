#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>
#include <queue>
#include <string>
#include "Matrix.h"

class Solver {
    private:
        Matrix m; int rows; int columns;
        std::queue<std::string> commands;

    public:
        Solver(Matrix _m){
            m = _m; 
            rows = m.getDimensions().at(0);
            columns = m.getDimensions().at(1);
        }

        void solve();
        void printMatrix();
};

#endif
