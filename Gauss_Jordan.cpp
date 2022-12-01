#include "Gauss_Jordan.h"
#include <vector>
#include <string>
#include <iostream>

// dependency of combinations.cpp (loose coupling)

GaussJordan::GaussJordan(Matrix m){
    user_matrix = m;
};

bool GaussJordan::isReduced(){
    
}

void GaussJordan::reduceColumn(int column, int pivot, int i){
    // find a value that when I combine the pivot with the current column value will be equal to zero
    for(int j = 0; j < user_matrix.getDimensions().at(1); j++){
        if(j == i){continue;}
        else {
            int combined_value = 0;
            for(int z = -50; z < 50; z++){
                if((z*pivot+user_matrix.getEntry(i, column)) == 0){
                    combined_value = z;
                }
            }
            user_matrix.addMultiple(i, j, combined_value);
            std::string command = std::to_string(combined_value);
            command += "AM";
            commands.push(command);
        }
    }
}

extern std::vector<std::vector<std::string>> Combinations(int depth); // provides all combinations (file reading takes longer than generation)

void GaussJordan::solve(){
    int rows = user_matrix.getDimensions().at(0); int columns = user_matrix.getDimensions().at(1);
    for(int i = 1; i < rows; i++){
        if(i-1 < columns){
            int *current_row = user_matrix.getRow(i);
            int pivot_value = current_row[i-1];
            reduceColumn(i-1, pivot_value, i-1);
            std::cout << pivot_value << "\n";
        } else {break;}
    }
}

void GaussJordan::printCommands(){
    while(!commands.empty()){
        std::cout << commands.front() << "\n";
        commands.pop();
    }
}   

