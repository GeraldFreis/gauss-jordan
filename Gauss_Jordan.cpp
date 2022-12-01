#include "Gauss_Jordan.h"
#include <vector>
#include <string>
#include <iostream>

// dependency of combinations.cpp (loose coupling)

GaussJordan::GaussJordan(Matrix m){
    user_matrix = m;
};

extern std::vector<std::vector<std::string>> Combinations(int depth); // provides all combinations (file reading takes longer than generation)

void GaussJordan::solve(){
    std::cout << user_matrix.getDimensions().at(0) << " " << user_matrix.getDimensions().at(1);
}