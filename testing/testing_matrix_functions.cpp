#include "../Matrix.h"
#include <iostream>
#include <string>

extern std::vector<int> string_to_numbers(std::string raw_input);


int main(){
    // Matrix m;
    std::string raw_dimensions, raw_input;
    std::cout << "What are the dimensions of the matrix?: (rows,columns)"  << "\n";
    std::getline(std::cin, raw_dimensions, '\n');


    std::cout << "Please enter the elements of the matrix row by row in a line: " << "\n";
    std::getline(std::cin, raw_input, '\n');

    std::vector<int> numbers = string_to_numbers(raw_input);

    // for(auto a: numbers){
    //     std::cout << a << " ";
    // }
    Matrix ma(numbers, raw_dimensions);
    ma.printElements();

    std::cout << "\n";
    // testing the add multiple functions
    ma.addMultiple(1,2,3);
    ma.printElements();

    std::cout << "\n";
    
    // testing the take multiple functions
    ma.takeMultiple(1,2,3);
    ma.printElements();
    std::cout << "\n";
    ma.swapRow(2,1);
    ma.printElements();
    return 0;
}
