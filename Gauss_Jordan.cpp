#include "Gauss_Jordan.h"
#include <vector>
#include <string>
#include <iostream>


GaussJordan::GaussJordan(Matrix m){
    user_matrix = m;
};

bool GaussJordan::isReduced(){
    // check if rows > columns
    if(user_matrix.getDimensions().at(0) > user_matrix.getDimensions().at(1)){
        int *last_row = user_matrix.getRow(user_matrix.getDimensions().at(0));
        for(int i = 0; i < user_matrix.getDimensions().at(1); i++){
            if(last_row[i]!=0){return false;}
        }
    }

    for(int i = 0; i < user_matrix.getDimensions().at(1); i++){
        for(int j = 0; j < user_matrix.getDimensions().at(0); j++){
            int pivot = i;
            if(i!=j){
                if(user_matrix.getEntry(pivot,j)!=0){return false;}
            }
        }
    }
    return true;
}

void GaussJordan::reduceColumn(int column, int pivot, int i){
    // find a value that when I combine the pivot with the current column value will be equal to zero
    for(int j = 0; j < user_matrix.getDimensions().at(0); j++){
        for(int z = -50; z < 50; z++){
            if(z*pivot + user_matrix.getEntry(j,i) == 0){
                user_matrix.addMultiple(i, j, z);
                std::string command = std::to_string(z) + "AM";
                commands.push(command);
            }
        }
    }
}

void GaussJordan::testCombination(std::vector<std::string> current_combination){
    // I want to interpret each step in the combination, pass this into another function which executes that step
    for(auto combination: current_combination){
        if(combination == "AM"){
            
        }
    }
}

extern std::vector<std::vector<std::string>> Combinations(int depth); // provides all combinations (file reading takes longer than generation)

void GaussJordan::solve(){
    int rows = user_matrix.getDimensions().at(0); int columns = user_matrix.getDimensions().at(1);
    std::vector<std::vector<std::string>> all_combinations = Combinations(15);
    while(!all_combinations.empty() && !isReduced()){

    }
    for(int i = 1; i < columns; i++){
        if(i-1 < columns){
            int *current_row = user_matrix.getRow(i);
            int pivot_value = current_row[i-1];
            reduceColumn(i-1, pivot_value, i-1);
            // std::cout << pivot_value << "\n";
        } else {break;}
    }
}

void GaussJordan::printCommands(){
    while(!commands.empty()){
        std::cout << commands.front() << "\n";
        commands.pop();
    }
}   

void GaussJordan::printMatrix(){
    user_matrix.printElements();
}

