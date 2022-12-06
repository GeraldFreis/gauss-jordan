#include "Gauss_Jordan.h"
#include "Matrix.h"
#include <iostream>
#include <vector>
#include <string>


GaussJordan::GaussJordan(Matrix m){
    user_matrix = m;
    rows = user_matrix.getDimensions().at(0);
    columns = user_matrix.getDimensions().at(1);
}

bool allZeros(int *row, int len){
    for(int i = 0; i < len; i++){
        if(row[i] != 0){
            return false;
        }
    }
    return true;
}

int pivotPosition(int *row, int len){
    for(int i = 0; i < len; i++){
        if(row[i] != 0){
            return i;
        }
    }
    return 0;
}

bool isPivot(int *column, int len, int pivot_position){
    for(int i = 0; i < len; i++){
        if(column[i] != 0 && i != pivot_position){
            return false;
        }
    }
    return true;
}

// private:

//checking if the user_matrix matrix is reduced
bool GaussJordan::isReduced(){
    /* 
    for a matrix to be in row reduced form:
        Rows composed only of zeros must be in the last row
        left-most non-zero entry of each row must be a pivot
        each pivot is further to the right of the row preceeding it
    */ 

   // check if there is a row of zeros 
   for(int i = 0; i < rows; i++){
        int *current_row = user_matrix.getRow(i);
        if(i != (rows-1)){
            if(allZeros(current_row, columns) == true){
                return false;
            }
        }
   }

   // checking if left-most non-zero is a pivot
        // iterate across every row and check that the last pivot is further left than the preceding pivots
    int last_pivot = 0;
    for(int i = 0; i < rows; i++){
        int *current_row = user_matrix.getRow(i);
        int this_pivot = pivotPosition(current_row, columns);
        if(this_pivot <= last_pivot){return false;}
        else {last_pivot = this_pivot;}
    }

    // checking if every pivot is in fact a pivot
        // iterate across every row and get the pivot position
        // iterate across every column and check if the pivot is an actual pivot
    int *pivot_array = new int[columns];

    if(rows >= columns){
        for(int i = 0; i < columns; i++){
            int *current_row = user_matrix.getRow(i);
            pivot_array[i] = pivotPosition(current_row, columns);
        }
    }

    for(int i = 0; i < columns; i++){
        int *current_column = user_matrix.getColumn(i);
        if(isPivot(current_column, columns, pivot_array[i]) == false){
            return false;
        }
    }

    return true;
}




// checking if the given combination will produce a result
bool GaussJordan::checkCombination(std::vector<std::string> current_combination){
    while(isReduced() == false && current_combination.size() != 0){
        std::string command = current_combination.at(0);
        current_combination.erase(current_combination.begin());

        if(command == "AM"){
            // iterating across the matrix
        }
    }
}

 // public:
extern std::vector<std::vector<std::string>> Combinations(int depth);

void GaussJordan::solve(){
    std::vector<std::vector<std::string>> found_combinations = Combinations(15);
    // iterating over all combinations and passing them into the checkCombination function
    for(auto combination: found_combinations){
        if(!checkCombination(combination)){}
    }
}
void GaussJordan::printCommands(){

}
void GaussJordan::printMatrix(){

}