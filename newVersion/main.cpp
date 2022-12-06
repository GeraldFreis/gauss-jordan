#include <iostream>
#include "../Gauss_Jordan.h"
#include "../Matrix.h"

extern std::vector<int> string_to_numbers(std::string raw_input);


int main(){
    std::string raw_dimensions, raw_input;
    std::cout << "What are the dimensions of the matrix?: (rows,columns)"  << "\n";
    std::getline(std::cin, raw_dimensions, '\n');


    std::cout << "Please enter the elements of the matrix row by row in a line: " << "\n";
    std::getline(std::cin, raw_input, '\n');

    std::vector<int> numbers = string_to_numbers(raw_input);

    Matrix m(numbers, raw_dimensions);
    
    GaussJordan GJ(m);
    GJ.solve();
    GJ.printCommands();
    GJ.printMatrix();
}