#include <iostream>
#include "Matrix.h"
#include "Solver.h"

extern std::vector<int> string_to_numbers(std::string raw_input);
extern std::vector<std::string> ReadingFile();

int main(){
    // std::string raw_dimensions, raw_input;
    // std::cout << "What are the dimensions of the matrix?: (rows,columns)"  << "\n";
    // std::getline(std::cin, raw_dimensions, '\n');


    // std::cout << "Please enter the elements of the matrix row by row in a line: " << "\n";
    // std::getline(std::cin, raw_input, '\n');


    std::string raw_dimensions, raw_input;
    raw_dimensions = ReadingFile().at(0); raw_input = ReadingFile().at(1);

    std::vector<int> numbers = string_to_numbers(raw_input);

    Matrix m_1(numbers, raw_dimensions);

    std::cout << "\n";
    Solver s_1(m_1);
    s_1.solve();
    // s.printSteps();
    // s.printMatrix();
    std::cout << std::endl;

    raw_dimensions = ReadingFile().at(2); raw_input = ReadingFile().at(3);
    numbers = string_to_numbers(raw_input);

    Matrix m_2(numbers, raw_dimensions);

    std::cout << "\n";
    Solver s_2(m_2);
    s_2.solve();

    std::cout << std::endl;
    
    raw_dimensions = ReadingFile().at(4); raw_input = ReadingFile().at(5);
    numbers = string_to_numbers(raw_input);

    Matrix m_3(numbers, raw_dimensions);

    std::cout << "\n";
    Solver s_3(m_3);
    s_3.solve();

}