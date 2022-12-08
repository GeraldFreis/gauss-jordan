#include <iostream>
#include <string>
#include <vector>
#include "Matrix.h"
#include "Solver.h"

extern std::vector<int> string_to_numbers(std::string raw_input);
extern std::vector<std::string> ReadingFile();

int main(){
    std::vector<std::string> file_contents = ReadingFile();

    std::string raw_dimensions[4], raw_input[4];
    int dim_counter = 0; int inp_counter = 0;

    for(int i = 0; i < file_contents.size(); i++){
        if(i % 2 == 0){
            raw_dimensions[dim_counter] = file_contents.at(i);
            std::cout << file_contents.at(i) << "\n";
            dim_counter++;
        } else {
            raw_input[inp_counter] = file_contents.at(i);
            inp_counter++;
        }
    }

    std::vector<Matrix> matrices; std::vector<Solver> solvers;

    for(int i = 0; i < 4; i++){
        Matrix m(string_to_numbers(raw_input[i]), raw_dimensions[i]);
        matrices.push_back(m);
        Solver s(m);
        solvers.push_back(s);
    }

    for(auto matrix_to_solve: solvers){
        matrix_to_solve.solve();
    }

}